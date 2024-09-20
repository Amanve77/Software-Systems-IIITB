/*
============================================================================
Name : 8c.c
Author : Aman Verma
Description :  Write a separate program using signal system call to catch the following signals.
                    c. SIGFPE
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpe_handler(int signum) 
{
    printf("Caught signal SIGFPE: Floating Point Exception\n");
    exit(EXIT_FAILURE);
}

int main() 
{
    signal(SIGFPE, sigfpe_handler);

    printf("Causing floating-point exception...\n");
    int x = 1 / 0;  

    return 0;
}



/*
============================================================================
Output:
    Causing floating-point exception...
    Caught signal SIGFPE: Floating Point Exception
============================================================================
*/