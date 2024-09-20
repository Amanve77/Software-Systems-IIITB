/*
============================================================================
Name : 8b.c
Author : Aman Verma
Description :  Write a separate program using signal system call to catch the following signals.
                    b. SIGINT
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) 
{
    printf("Caught signal SIGINT: Interrupt signal (Ctrl+C)\n");
    _exit(0); 
}

int main() 
{
    signal(SIGINT, sigint_handler); 

    printf("Waiting for Ctrl+C (SIGINT)...\n");
    while (1)
        sleep(1); 

    return 0;
}



/*
============================================================================
Output:
    Waiting for Ctrl+C (SIGINT)...
    ^CCaught signal SIGINT: Interrupt signal (Ctrl+C)
============================================================================
*/