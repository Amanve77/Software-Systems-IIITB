/*
============================================================================
Name : 2.c
Author : Aman Verma
Description : Write a program to print the system resource limits. Use getrlimit system call. 
Date: 17th Sept, 2024.
============================================================================
*/


#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>

void sys_rlimit(int r_type, const char* r_name)
{
    struct rlimit limit;

    if(getrlimit(r_type, &limit)==0)
        printf("\t%s : \n\t\t\tSoft limit=%ld  Hard Limit=%ld\n",r_name, (long)limit.rlim_cur, (long)limit.rlim_max);
    else
    {
        perror("Error getting resourse limit\n");
        exit(1);
    }
}

int main()
{
    printf("System Resources Limits are given below:\n\n");

    sys_rlimit(RLIMIT_CPU, "CPU Time (seconds)");
    sys_rlimit(RLIMIT_FSIZE, "Max File Size (bytes)");
    sys_rlimit(RLIMIT_DATA, "Max Data Segment Size (bytes)");
    sys_rlimit(RLIMIT_STACK, "Max Stack Size (bytes)");
    sys_rlimit(RLIMIT_CORE, "Max Core File Size (bytes)");
    sys_rlimit(RLIMIT_NOFILE, "Max Open Files");
    sys_rlimit(RLIMIT_AS, "Max Virtual Memory (bytes)");

    return 0;
}

/*
============================================================================
Output:
    System Resources Limits are given below:

        CPU Time (seconds) : 
                        Soft limit=-1  Hard Limit=-1
        Max File Size (bytes) : 
                        Soft limit=-1  Hard Limit=-1
        Max Data Segment Size (bytes) : 
                        Soft limit=-1  Hard Limit=-1
        Max Stack Size (bytes) : 
                        Soft limit=8388608  Hard Limit=-1
        Max Core File Size (bytes) : 
                        Soft limit=0  Hard Limit=-1
        Max Open Files : 
                        Soft limit=1048576  Hard Limit=1048576
        Max Virtual Memory (bytes) : 
                        Soft limit=-1  Hard Limit=-1
============================================================================
*/