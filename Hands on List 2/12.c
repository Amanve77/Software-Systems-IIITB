/*
============================================================================
Name : 12.c
Author : Aman Verma
Description :  Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process. 
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle_sigkill(int signum) 
{
    printf("Parent process received SIGKILL\n");
    exit(EXIT_SUCCESS);
}

int main() 
{
    pid_t pid;

    pid = fork();

    if (pid < 0) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) 
    {
        printf("Child process (PID: %d) created.\n", getpid());
        sleep(2);
        printf("Child process (PID: %d) sending SIGKILL to parent (PID: %d).\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
        exit(EXIT_SUCCESS);
    } 
    else 
    {
        printf("Parent process (PID: %d) running...\n", getpid());
        signal(SIGKILL, handle_sigkill);

        wait(NULL);

        printf("Parent process (PID: %d) exiting...\n", getpid());
        exit(EXIT_SUCCESS);
    }

    return 0;
}


/*
============================================================================
Output:
    Parent process (PID: 15065) running...
    Child process (PID: 15066) created.
    Child process (PID: 15066) sending SIGKILL to parent (PID: 15065).
    Killed
============================================================================
*/