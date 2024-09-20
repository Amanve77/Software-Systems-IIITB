/*
============================================================================
Name : 13a.c
Author : Aman Verma
Description :  Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). 
               Find out whether the first program is able to catch the signal or not.  
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) 
{
    printf("Caught signal %d\n", signum);
}

int main() 
{
    struct sigaction sa;

    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    printf("Waiting for signals. Send SIGUSR1 from another process to test.\n");

    while (1)
        pause();

    return 0;
}


/*
============================================================================
Output:
    Waiting for signals. Send SIGUSR1 from another process to test.
    Caught signal 10
============================================================================
*/