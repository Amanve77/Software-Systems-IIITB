/*
============================================================================
Name : 8g.c
Author : Aman Verma
Description :  Write a separate program using signal system call to catch the following signals.
                    g. SIGPROF (use setitimer system call)  
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigprof_handler(int signum) 
{
    printf("Caught signal SIGPROF: Profiling timer alarm triggered\n");
}

int main() 
{
    signal(SIGPROF, sigprof_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 2; 
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);
    printf("Waiting for profiling timer alarm...\n");

    while(1);

    return 0;
}


/*
============================================================================
Output:
    Waiting for profiling timer alarm...
    Caught signal SIGPROF: Profiling timer alarm triggered
============================================================================
*/