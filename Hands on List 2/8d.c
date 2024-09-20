/*
============================================================================
Name : 8d.c
Author : Aman Verma
Description :  Write a separate program using signal system call to catch the following signals.
                    d. SIGALRM (use alarm system call)
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int signum) 
{
    printf("Caught signal SIGALRM: Alarm triggered\n");
}

int main() 
{
    signal(SIGALRM, sigalrm_handler); 

    alarm(3); 
    printf("Waiting for alarm...\n");

    pause(); 

    return 0;
}



/*
============================================================================
Output:
    Waiting for alarm...
    Caught signal SIGALRM: Alarm triggered
============================================================================
*/