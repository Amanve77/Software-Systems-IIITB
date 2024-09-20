/*
============================================================================
Name : 21a.c
Author : Aman Verma
Description :  Write two programs so that both can communicate by FIFO -Use two way communications.  
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>


int main() 
{
    int fd_write, fd_read;
    char write_msg[100] = "Hello from Program 1!";
    char read_msg[100];

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    fd_write = open("fifo1", O_WRONLY);
    fd_read = open("fifo2", O_RDONLY);

    while(1) 
    {
        printf("Program 1: Enter a message to send: ");
        fgets(write_msg, sizeof(write_msg), stdin);

        write(fd_write, write_msg, strlen(write_msg) + 1);
        printf("Program 1: Sent message: %s", write_msg);

        read(fd_read, read_msg, sizeof(read_msg));
        printf("Program 1: Received message: %s\n", read_msg);
    }

    close(fd_write);
    close(fd_read);

    return 0;
}


/*
============================================================================
Output:
    Program 1: Enter a message to send: Hi program 2
    Program 1: Sent message: Hi program 2
    Program 1: Received message: Hello program 1

    Program 1: Enter a message to send: bye
    Program 1: Sent message: bye
    Program 1: Received message: ok bye
============================================================================
*/