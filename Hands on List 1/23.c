/*
============================================================================
Name : 23.c
Author : Aman Verma
Description : Write a program to create a Zombie state of the running program.  
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if(pid < 0) 
    {
        perror("Fork failed");
        return 1;
    } 
    else if(pid == 0) 
    {
        printf("Child process started, PID: %d\n", getpid());
        exit(0); 
    } 
    else 
    {
        printf("Parent process, PID: %d\n", getpid());
        sleep(10);
        wait(NULL);

        printf("Child process cleaned up.\n");
    }

    return 0;
}

/*
============================================================================
Output:
    Program:
        Parent process, PID: 7863
        Child process started, PID: 7865
        Child process cleaned up.


    Check for zombie process:
        USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
        aman-ve+    7865  0.0  0.0      0     0 pts/0    Z+   23:31   0:00 [a.out] <defunct>
============================================================================
*/
