/*
============================================================================
Name : 25.c
Author : Aman Verma
Description :  Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                a. access permission
                b. uid, gid
                c. time of last message sent and received
                d. time of last change in the message queue
                d. size of the queue
                f. number of messages in the queue
                g. maximum number of bytes allowed
                h. pid of the msgsnd and msgrcv 
Date: 20th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <time.h>

void print_message_queue_info(int msgid) 
{
    struct msqid_ds mq_info;

    if (msgctl(msgid, IPC_STAT, &mq_info) == -1) 
    {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Access Permissions: %o\n", mq_info.msg_perm.mode);
    printf("User ID (UID): %d\n", mq_info.msg_perm.uid);
    printf("Group ID (GID): %d\n", mq_info.msg_perm.gid);
    printf("Time of Last Message Sent: %s", ctime(&mq_info.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&mq_info.msg_rtime));
    printf("Time of Last Change: %s", ctime(&mq_info.msg_ctime));
    printf("Size of the Queue (bytes): %lu\n", mq_info.__msg_cbytes);
    printf("Number of Messages in the Queue: %lu\n", mq_info.msg_qnum);
    printf("Maximum Number of Bytes Allowed: %lu\n", mq_info.msg_qbytes);
    printf("PID of Last msgsnd: %d\n", mq_info.msg_perm.cuid);
    printf("PID of Last msgrcv: %d\n", mq_info.msg_perm.uid);
}

int main() 
{
    key_t key = ftok("yourfile", 'A');  
    int msgid = msgget(key, 0666 | IPC_CREAT); 

    if (msgid == -1) 
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    print_message_queue_info(msgid);

    return 0;
}


/*
============================================================================
Output:
    Access Permissions: 666
    User ID (UID): 1000
    Group ID (GID): 1000
    Time of Last Message Sent: Thu Jan  1 05:30:00 1970
    Time of Last Message Received: Thu Jan  1 05:30:00 1970
    Time of Last Change: Sat Sep 21 02:19:11 2024
    Size of the Queue (bytes): 0
    Number of Messages in the Queue: 0
    Maximum Number of Bytes Allowed: 16384
    PID of Last msgsnd: 1000
    PID of Last msgrcv: 1000
============================================================================
*/