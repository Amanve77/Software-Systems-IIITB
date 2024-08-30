/*
============================================================================
Name : 21.c
Author : Aman Verma
Description : Write a program, call fork and print the parent and child process id. 
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    pid = fork();

    if(pid < 0) 
    {
        perror("fork failed");
        return 1;
    } 
    else if(pid == 0) 
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    else 
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);

    return 0;
}
/*
============================================================================
Output:
    Parent process: PID = 8704, Child PID = 8705
    Child process: PID = 8705, Parent PID = 8704
============================================================================
*/