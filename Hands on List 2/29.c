/*
============================================================================
Name : 29.c
Author : Aman Verma
Description :  Write a program to remove the message queue.  
Date: 20th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() 
{
    key_t key = ftok("fifo_file", 65); 
    if (key == -1) 
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    int msgid = msgget(key, 0666);
    if (msgid == -1) 
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Message queue found with ID: %d\n", msgid);

    if (msgctl(msgid, IPC_RMID, NULL) == -1) 
    {
        perror("msgctl IPC_RMID");
        exit(EXIT_FAILURE);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}



/*
============================================================================
Output:
    Message queue found with ID: 2
    Message queue removed successfully.
============================================================================
*/