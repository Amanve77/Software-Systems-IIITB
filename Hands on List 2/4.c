/*
============================================================================
Name : 4.c
Author : Aman Verma
Description :  Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter. 
Date: 17th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

static inline uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    
    start = rdtsc();

    for (int i = 0; i < 100; i++) {
        getppid();
    }

    end = rdtsc();

    uint64_t total_cycles = end - start;
    
    printf("Time taken for 100 getppid() calls: %lu CPU cycles\n", total_cycles);

    return 0;
}

/*
============================================================================
Output:
    Time taken for 100 getppid() calls: 84810 CPU cycles
============================================================================
*/