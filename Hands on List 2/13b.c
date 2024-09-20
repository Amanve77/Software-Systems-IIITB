/*
============================================================================
Name : 13b.c
Author : Aman Verma
Description :  Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). 
               Find out whether the first program is able to catch the signal or not.  
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid = (pid_t)atoi(argv[1]);

    if (kill(pid, SIGUSR1) == -1) 
    {
        perror("kill");
        exit(EXIT_FAILURE);
    }

    printf("Sent SIGUSR1 to process %d\n", pid);

    return 0;
}


/*
============================================================================
Output:
    Waiting for signals. Send SIGUSR1 from another process to test.
    Caught signal 10
============================================================================
*/