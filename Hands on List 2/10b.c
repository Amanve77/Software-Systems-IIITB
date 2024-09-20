/*
============================================================================
Name : 10b.c
Author : Aman Verma
Description :  Write a separate program using sigaction system call to catch the following signals.
                    b. SIGINT
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum, siginfo_t *info, void *context) 
{
    printf("Caught signal SIGINT: Interrupt signal (Ctrl+C)\n");
}

int main() 
{
    struct sigaction sa;
    sa.sa_sigaction = sigint_handler;
    sa.sa_flags = SA_SIGINFO; 

    sigaction(SIGINT, &sa, NULL); 

    printf("Waiting for Ctrl+C (SIGINT)...\n");
    while (1) {
        sleep(1); 
    }

    return 0;
}


/*
============================================================================
Output:
    Waiting for Ctrl+C (SIGINT)...
    ^CCaught signal SIGINT: Interrupt signal (Ctrl+C)
    ^CCaught signal SIGINT: Interrupt signal (Ctrl+C)
    .
    .
    .
============================================================================
*/