/*
============================================================================
Name : 3.c
Author : Aman Verma
Description :  Write a program to set (any one) system resource limit. Use setrlimit system call. 
Date: 17th Sept, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/resource.h>


int main()
{
    struct rlimit limit;

    if(getrlimit(RLIMIT_NOFILE, &limit)==0)
        printf("Old Max No. of open files\n\tSoft limit:%ld  Hard Limit:%ld\n",(long)limit.rlim_cur,(long)limit.rlim_max);
    else
    {
        perror("Error while getting old limits\n");
        exit(1);
    }

    limit.rlim_cur=148576;
    limit.rlim_max=148576;

    if(setrlimit(RLIMIT_NOFILE, &limit)==0)
        printf("New Limits has been set\n");
    else
    {
        perror("Error while setting new limits\n");
        exit(1);
    }


    if(getrlimit(RLIMIT_NOFILE, &limit)==0)
        printf("New Max No. of open files\n\tSoft limit:%ld  Hard Limit:%ld\n",(long)limit.rlim_cur,(long)limit.rlim_max);
    else
    {
        perror("Error while getting old limits\n");
        exit(1);
    }

    return 0;
}

/*
============================================================================
Output:
    Old Max No. of open files
        Soft limit:1048576  Hard Limit:1048576
    New Limits has been set
    New Max No. of open files
        Soft limit:148576  Hard Limit:148576
============================================================================
*/
