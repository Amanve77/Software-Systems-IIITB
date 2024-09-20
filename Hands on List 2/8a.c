/*
============================================================================
Name : 8a.c
Author : Aman Verma
Description :  Write a separate program using signal system call to catch the following signals.
                    a. SIGSEGV  
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void sigsegv_handler(int signum) 
{
    printf("Caught signal SIGSEGV: Segmentation Fault\n");
    exit(EXIT_FAILURE);  
}

int main() 
{
    signal(SIGSEGV, sigsegv_handler); 

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