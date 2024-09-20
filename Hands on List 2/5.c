/*
============================================================================
Name : 4.c
Author : Aman Verma
Description :  Write a program to print the system limitation of
                a. maximum length of the arguments to the exec family of functions.
                b. maximum number of simultaneous process per user id.
                c. number of clock ticks (jiffy) per second.
                d. maximum number of open files
                e. size of a page
                f. total number of pages in the physical memory
                g. number of currently available pages in the physical memory.  
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() 
{
    long arg_max = sysconf(_SC_ARG_MAX);
    if (arg_max == -1)
        perror("sysconf");
    else
        printf("Maximum length of arguments to exec: %ld bytes\n", arg_max);

    long max_procs = sysconf(_SC_CHILD_MAX);
    if (max_procs == -1)
        perror("sysconf");
    else
        printf("Maximum number of simultaneous processes per user: %ld\n", max_procs);

    long clock_ticks = sysconf(_SC_CLK_TCK);
    if (clock_ticks == -1)
        perror("sysconf");
    else
        printf("Number of clock ticks per second: %ld\n", clock_ticks);

    struct rlimit lim;
    if (getrlimit(RLIMIT_NOFILE, &lim) == 0) {
        printf("Maximum number of open files: Soft limit = %ld, Hard limit = %ld\n", lim.rlim_cur, lim.rlim_max);
    } else {
        perror("getrlimit");
    }

    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size == -1)
        perror("sysconf");
    else
        printf("Size of a page: %ld bytes\n", page_size);

    long total_pages = sysconf(_SC_PHYS_PAGES);
    if (total_pages == -1)
        perror("sysconf");
    else
        printf("Total number of pages in physical memory: %ld pages\n", total_pages);

    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    if (avail_pages == -1)
        perror("sysconf");
    else
        printf("Number of available pages in physical memory: %ld pages\n", avail_pages);

    return 0;
}

/*
============================================================================
Output:
    Maximum length of arguments to exec: 2097152 bytes
    Maximum number of simultaneous processes per user: 61031
    Number of clock ticks per second: 100
    Maximum number of open files: Soft limit = 1048576, Hard limit = 1048576
    Size of a page: 4096 bytes
    Total number of pages in physical memory: 3923782 pages
    Number of available pages in physical memory: 1699064 pages
============================================================================
*/