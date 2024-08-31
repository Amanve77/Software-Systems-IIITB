/*
============================================================================
Name : 29.c
Author : Aman Verma
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 31th Aug, 2024.
============================================================================
*/


#include <sched.h> 
#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>     
#include <stdlib.h> 

int main()
{
    int currentPolicy;
    pid_t pid;
    pid = getpid();
    currentPolicy = sched_getscheduler(pid);
    if(currentPolicy == -1) 
    {
        perror("sched_setscheduler");
        exit(0);
    }
    struct sched_param priority;
    
    priority.sched_priority = 10;

    switch (currentPolicy)
    {
        case SCHED_FIFO:
            printf("Current policy is FIFO\n");
            if(sched_setscheduler(pid, SCHED_RR, &priority) == -1)
            {
                perror("sched_setscheduler");
                exit(0);
            }
            break;
        case SCHED_RR:
            printf("Current policy is RR\n");
            if(sched_setscheduler(pid, SCHED_FIFO, &priority) == -1)
            {
                perror("sched_setscheduler");
                exit(0);
            }
            break;
        case SCHED_OTHER:
            printf("Current policy is OTHER\n");
            if(sched_setscheduler(pid, SCHED_RR, &priority) == -1)
            {
                perror("sched_setscheduler");
                exit(0);
            }
            break;
        default:
            perror("Error while getting current policy\n");
    }

    currentPolicy = sched_getscheduler(pid);
    if(currentPolicy == -1) 
    {
        perror("sched_getscheduler");
        exit(0);
    }
    switch(currentPolicy) 
    {
        case SCHED_FIFO:
            printf("New policy is SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("New policy is SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("New policy is SCHED_OTHER\n");
            break;
        default:
            printf("New policy is unrecognized (%d)\n", currentPolicy);
            break;
    }

    return 0;
}

/*
============================================================================
Output:
    Current policy is OTHER
    New policy is SCHED_RR
============================================================================
*/