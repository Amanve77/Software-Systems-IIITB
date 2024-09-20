/*
============================================================================
Name : 10c.c
Author : Aman Verma
Description :  Write a separate program using sigaction system call to catch the following signals.
                    c. SIGFPE  
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler for SIGFPE
void sigfpe_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught signal SIGFPE: Floating Point Exception\n");
    exit(EXIT_FAILURE);  // Exit after catching the signal
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = sigfpe_handler;
    sa.sa_flags = SA_SIGINFO;  // Use sa_sigaction instead of sa_handler

    sigaction(SIGFPE, &sa, NULL);  // Register signal handler

    int a = 1;
    int b = 0;

    printf("Causing floating-point exception...\n");

    int x = a / b;  // Trigger floating-point exception by dividing by zero

    return 0;
}


/*
============================================================================
Output:
    Causing floating-point exception...
    Caught signal SIGFPE: Floating Point Exception
============================================================================
*/