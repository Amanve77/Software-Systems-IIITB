/*
============================================================================
Name : 31.c
Author : Aman Verma
Description :  Write a program to create a semaphore and initialize value to the semaphore.
                    a. create a binary semaphore
                    b. create a counting semaphore 
Date: 20th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_ITERATIONS 3

sem_t binary_semaphore; 
sem_t counting_semaphore; 

void* binary_semaphore_example(void* arg) 
{
    printf("Thread %ld: Waiting for binary semaphore...\n", (long)arg);
    sem_wait(&binary_semaphore); 
    printf("Thread %ld: Acquired binary semaphore!\n", (long)arg);
    sleep(1); 
    printf("Thread %ld: Releasing binary semaphore...\n", (long)arg);
    sem_post(&binary_semaphore);
    return NULL;
}

void* counting_semaphore_example(void* arg) 
{
    printf("Thread %ld: Waiting for counting semaphore...\n", (long)arg);
    sem_wait(&counting_semaphore); 
    printf("Thread %ld: Acquired counting semaphore!\n", (long)arg);
    sleep(1); 
    printf("Thread %ld: Releasing counting semaphore...\n", (long)arg);
    sem_post(&counting_semaphore); 
    return NULL;
}

int main() 
{
    sem_init(&binary_semaphore, 0, 1);

    sem_init(&counting_semaphore, 0, 3); 

    pthread_t threads[NUM_ITERATIONS];

    for (long i = 0; i < NUM_ITERATIONS; i++) 
    {
        pthread_create(&threads[i], NULL, binary_semaphore_example, (void*)i);
    }

    for (long i = 0; i < NUM_ITERATIONS; i++) 
    {
        pthread_join(threads[i], NULL);
    }

    for (long i = 0; i < NUM_ITERATIONS; i++) 
    {
        pthread_create(&threads[i], NULL, counting_semaphore_example, (void*)i);
    }

    for (long i = 0; i < NUM_ITERATIONS; i++) 
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&binary_semaphore);
    sem_destroy(&counting_semaphore);

    printf("Semaphores destroyed successfully.\n");

    return 0;
}



/*
============================================================================
Output:
    Thread 0: Waiting for binary semaphore...
    Thread 0: Acquired binary semaphore!
    Thread 1: Waiting for binary semaphore...
    Thread 2: Waiting for binary semaphore...
    Thread 0: Releasing binary semaphore...
    Thread 1: Acquired binary semaphore!
    Thread 1: Releasing binary semaphore...
    Thread 2: Acquired binary semaphore!
    Thread 2: Releasing binary semaphore...
    Thread 0: Waiting for counting semaphore...
    Thread 0: Acquired counting semaphore!
    Thread 1: Waiting for counting semaphore...
    Thread 1: Acquired counting semaphore!
    Thread 2: Waiting for counting semaphore...
    Thread 2: Acquired counting semaphore!
    Thread 2: Releasing counting semaphore...
    Thread 0: Releasing counting semaphore...
    Thread 1: Releasing counting semaphore...
    Semaphores destroyed successfully.
============================================================================
*/