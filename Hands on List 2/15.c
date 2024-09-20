/*
============================================================================
Name : 15.c
Author : Aman Verma
Description :  Write a simple program to send some data from parent to the child process. 
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/wait.h>

int main() 
{
    int pipefd[2]; 
    pid_t pid;
    const char *message = "Hello from parent!";
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) 
    {
        close(pipefd[1]);

        ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer));
        if (bytesRead == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("Child received: %s\n", buffer);
        close(pipefd[0]); 
        exit(EXIT_SUCCESS);
    } 
    else 
    {
        close(pipefd[0]);
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]); 

        wait(NULL);
    }

    return 0;
}


/*
============================================================================
Output:
    Child received: Hello from parent!
============================================================================
*/