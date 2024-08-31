/*
============================================================================
Name : 24.c
Author : Aman Verma
Description :  Write a program to create an orphan process. 
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() 
{
    pid_t pid;

    pid = fork();

    if(pid < 0) 
    {
        perror("Fork failed");
        return 1;
    } 
    else if(pid == 0) 
    {
        printf("Child process, PID: %d, Parent PID: %d\n", getpid(), getppid());
        sleep(1);
        printf("Orphan child process started, PID: %d, Parent PID: %d\n", getpid(), getppid());

        sleep(10); 
        printf("Orphan child process completed, PID: %d, Parent PID: %d\n", getpid(), getppid());
    } 
    else
        printf("Parent process, PID: %d\n", getpid());

    return 0;
}

/*
============================================================================
Output:
    Parent process, PID: 8298
    Child process, PID: 8299, Parent PID: 8298
    Orphan child process started, PID: 8299, Parent PID: 1630
    Orphan child process completed, PID: 8299, Parent PID: 1630
============================================================================
*/