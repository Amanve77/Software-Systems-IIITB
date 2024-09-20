/*
============================================================================
Name : 16.c
Author : Aman Verma
Description :  Write a program to send and receive data from parent to child vice versa. Use two way communication. 
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/wait.h>

#define BUFFER_SIZE 100

int main() 
{
    int pipe1[2];
    int pipe2[2];
    pid_t pid;
    char parentMessage[] = "Hello from parent!";
    char childMessage[] = "Hello from child!";
    char buffer[BUFFER_SIZE];

    if (pipe(pipe1) == -1) 
    {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }

    if (pipe(pipe2) == -1) 
    {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) 
    {
        close(pipe1[1]); 
        close(pipe2[0]);

        ssize_t bytesRead = read(pipe1[0], buffer, sizeof(buffer));
        if (bytesRead == -1) {
            perror("read from parent");
            exit(EXIT_FAILURE);
        }
        printf("Child received: %s\n", buffer);

        write(pipe2[1], childMessage, strlen(childMessage) + 1);

        close(pipe1[0]); 
        close(pipe2[1]); 
        exit(EXIT_SUCCESS);
    } 
    else 
    {
        close(pipe1[0]);  
        close(pipe2[1]);  

        write(pipe1[1], parentMessage, strlen(parentMessage) + 1);

        ssize_t bytesRead = read(pipe2[0], buffer, sizeof(buffer));
        if (bytesRead == -1) {
            perror("read from child");
            exit(EXIT_FAILURE);
        }
        printf("Parent received: %s\n", buffer);

        close(pipe1[1]); 
        close(pipe2[0]);  

        wait(NULL);
    }

    return 0;
}


/*
============================================================================
Output:
    Child received: Hello from parent!
    Parent received: Hello from child!
============================================================================
*/