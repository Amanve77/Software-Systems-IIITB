/*
============================================================================
Name : 19.c
Author : Aman Verma
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter. 
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    int pid;

    start = rdtsc();
    pid = getpid();
    end = rdtsc();

    printf("Time taken for getpid() in CPU cycles: %lu\n", (end - start));

    return 0;
}
/*
============================================================================
Output:
    Time taken for getpid() in CPU cycles: 8712
============================================================================
*/