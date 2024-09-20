/*
============================================================================
Name : 6.c
Author : Aman Verma
Description :  Write a simple program to create three threads.  
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) 
{
    int thread_id = *((int*)arg);
    printf("Thread %d is running\n", thread_id);
    sleep(1); 
    printf("Thread %d is finished\n", thread_id);
    pthread_exit(NULL);
}

int main() 
{
    pthread_t threads[3];
    int thread_ids[3];
    int ret;

    for (int i = 0; i < 3; i++) 
    {
        thread_ids[i] = i + 1;
        ret = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if (ret != 0) 
        {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 3; i++) 
        pthread_join(threads[i], NULL);

    printf("All threads have finished execution.\n");
    return 0;
}


/*
============================================================================
Output:
    Thread 1 is running
    Thread 3 is running
    Thread 2 is running
    Thread 1 is finished
    Thread 2 is finished
    Thread 3 is finished
    All threads have finished execution.
============================================================================
*/