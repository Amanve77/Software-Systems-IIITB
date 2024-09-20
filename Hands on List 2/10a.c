/*
============================================================================
Name : 10a.c
Author : Aman Verma
Description :  Write a separate program using sigaction system call to catch the following signals.
                    a. SIGSEGV
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigsegv_handler(int signum, siginfo_t *info, void *context) 
{
    printf("Caught signal SIGSEGV: Segmentation Fault\n");
    exit(EXIT_FAILURE);
}

int main() 
{
    struct sigaction sa;
    sa.sa_sigaction = sigsegv_handler;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGSEGV, &sa, NULL) == -1) 
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    } 

    printf("Causing segmentation fault...\n");
    int *ptr = NULL;
    *ptr = 42; 

    return 0;
}



/*
============================================================================
Output:
    Causing segmentation fault...
    Caught signal SIGSEGV: Segmentation Fault
============================================================================
*/