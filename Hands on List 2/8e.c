/*
============================================================================
Name : 8e.c
Author : Aman Verma
Description :  Write a separate program using signal system call to catch the following signals.
                    e. SIGALRM (use setitimer system call)
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigalrm_handler(int signum) 
{
    printf("Caught signal SIGALRM: Alarm triggered by setitimer\n");
}

int main() 
{
    signal(SIGALRM, sigalrm_handler); 

    struct itimerval timer;
    timer.it_value.tv_sec = 2; 
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);  
    printf("Waiting for alarm...\n");

    pause();

    return 0;
}



/*
============================================================================
Output:
    Waiting for alarm...
    Caught signal SIGALRM: Alarm triggered by setitimer
============================================================================
*/