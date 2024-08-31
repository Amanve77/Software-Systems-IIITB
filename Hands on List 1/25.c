/*
============================================================================
Name : 25.c
Author : Aman Verma
Description : Write a program to create three child processes. The parent should wait for a particular child (use
              waitpid system call).
Date: 31th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    int pid1, pid2, pid3;
    int target_pid;
    int status;

   
    pid1 = fork();
    if(pid1 == 0) 
    {
        printf("First child (PID: %d) is running\n", getpid());
        sleep(2); 
        printf("First child (PID: %d) is exiting\n", getpid());
        exit(0);
    }

   
    pid2 = fork();
    if(pid2 == 0) 
    {    
        printf("Second child (PID: %d) is running\n", getpid());
        sleep(4); 
        printf("Second child (PID: %d) is exiting\n", getpid());
        exit(0);
    }

    pid3 = fork();
    if (pid3 == 0) 
    {   
        printf("Third child (PID: %d) is running\n", getpid());
        sleep(6);  
        printf("Third child (PID: %d) is exiting\n", getpid());
        exit(0);
    }

    target_pid = pid2;
    printf("Parent (PID: %d) is waiting for the second child (PID: %d) to finish\n", getpid(), target_pid);
    waitpid(target_pid, &status, 0);

    if(WIFEXITED(status)) 
        printf("Parent (PID: %d) detected that the second child (PID: %d)\n", getpid(), target_pid);
    else
        printf("Parent (PID: %d) detected that the second child (PID: %d) did not exit normally.\n", getpid(), target_pid);

    printf("Parent (PID: %d) is exiting.\n", getpid());

    return 0;
}
/*
============================================================================
Output:
    First child (PID: 5400) is running
    Second child (PID: 5401) is running
    Parent (PID: 5399) is waiting for the second child (PID: 5401) to finish
    Third child (PID: 5402) is running
    First child (PID: 5400) is exiting
    Second child (PID: 5401) is exiting
    Parent (PID: 5399) detected that the second child (PID: 5401)
    Parent (PID: 5399) is exiting.
    Third child (PID: 5402) is exiting
============================================================================
*/