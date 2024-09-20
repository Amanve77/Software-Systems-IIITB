/*
============================================================================
Name : 7.c
Author : Aman Verma
Description :  Write a simple program to print the created thread ids. 
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) 
{
    printf("Thread %ld is running\n", pthread_self());
    pthread_exit(NULL);
}

int main() 
{
    pthread_t threads[3];
    int ret;

    for (int i = 0; i < 3; i++) 
    {
        ret = pthread_create(&threads[i], NULL, thread_function, NULL);
        if (ret != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
        printf("Thread %d created with ID: %ld\n", i + 1, threads[i]);
    }


    for (int i = 0; i < 3; i++) 
        pthread_join(threads[i], NULL);

    printf("All threads have finished execution.\n");
    return 0;
}


/*
============================================================================
Output:
    Thread 1 created with ID: 129765386225344
    Thread 129765386225344 is running
    Thread 2 created with ID: 129765375739584
    Thread 129765375739584 is running
    Thread 3 created with ID: 129765365253824
    Thread 129765365253824 is running
    All threads have finished execution.
============================================================================
*/