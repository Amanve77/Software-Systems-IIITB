/*
============================================================================
Name : 17a.c
Author : Aman Verma
Description :  Write a program to execute ls -l | wc.
                    a. use dup
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
        close(STDIN_FILENO);
        dup(pipefd[0]); 
        close(pipefd[1]); 
        execl("/usr/bin/wc", "wc", NULL);
    }

    pid2 = fork();
    if (pid2 == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) 
    {
        close(STDOUT_FILENO);
        dup(pipefd[1]); 
        close(pipefd[0]);
        execl("/usr/bin/ls", "ls -l", "-l", NULL);
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