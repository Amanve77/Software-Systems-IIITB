/*
============================================================================
Name : 1a.c
Author : Aman Verma
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
                a. ITIMER_REAL
Date: 17th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void timer_handler(int signum) 
{
    static int i=1;
    printf("ITIMER_REAL timer expired %d time\n", i);
    i++;
}

int main() 
{
    signal(SIGALRM, timer_handler);

    printf("Starting timer...\n");

    struct itimerval timer;
    
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) 
    {
        perror("setitimer");
    }

    while(1)
        pause();

    return 0;
}

/*
============================================================================
Output:
    Starting timer...
    ITIMER_REAL timer expired 1 time
    ITIMER_REAL timer expired 2 time
    .
    .
    .
    .
============================================================================
*/
