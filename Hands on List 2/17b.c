/*
============================================================================
Name : 17b.c
Author : Aman Verma
Description :  Write a program to execute ls -l | wc.
                    b. use dup2
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() 
{
    int pipefd[2];
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1) 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();
    if (pid1 == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) 
    {
        close(pipefd[0]); 

        dup2(pipefd[1], STDOUT_FILENO);

        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    pid2 = fork();
    if (pid2 == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) 
    {
        close(pipefd[1]);

        dup2(pipefd[0], STDIN_FILENO);

        execlp("wc", "wc", (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    close(pipefd[0]); 
    close(pipefd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}


/*
============================================================================
Output:
         51     452    2980
============================================================================
*/