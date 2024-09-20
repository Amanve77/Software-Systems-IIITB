/*
============================================================================
Name : 30.c
Author : Aman Verma
Description :  Write a program to create a shared memory.
                a. write some data to the shared memory
                b. attach with O_RDONLY and check whether you are able to overwrite.
                c. detach the shared memory
                d. remove the shared memory  
Date: 20th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() 
{
    key_t key = ftok("/tmp", 65);
    if (key == -1) 
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); 
    if (shmid == -1) 
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *data = (char*) shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) 
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    strcpy(data, "Hello, Shared Memory!");
    printf("Data written to shared memory: %s\n", data);

    if (shmdt(data) == -1) 
    {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    char *readonly_data = (char*) shmat(shmid, NULL, SHM_RDONLY);
    if (readonly_data == (char *)(-1)) 
    {
        perror("shmat (readonly)");
        exit(EXIT_FAILURE);
    }
    printf("Data read from shared memory: %s\n", readonly_data);

    //strcpy(readonly_data, "Trying to overwrite..."); // This will trigger a segmentation fault when we try to overwrite.

    if (shmdt(readonly_data) == -1) 
    {
        perror("shmdt (readonly)");
        exit(EXIT_FAILURE);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) 
    {
        perror("shmctl IPC_RMID");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory removed successfully.\n");

    return 0;
}


/*
============================================================================
Output:
    Data written to shared memory: Hello, Shared Memory!
    Data read from shared memory: Hello, Shared Memory!
    Shared memory removed successfully.
============================================================================
*/