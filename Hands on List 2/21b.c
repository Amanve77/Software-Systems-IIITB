/*
============================================================================
Name : 21b.c
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
    int fd_read, fd_write;
    char read_msg[100];
    char write_msg[100] = "Hello from Program 2!";

    fd_read = open("fifo1", O_RDONLY);
    fd_write = open("fifo2", O_WRONLY);

    while(1) 
    {
        read(fd_read, read_msg, sizeof(read_msg));
        printf("Program 2: Received message: %s\n", read_msg);

        printf("Program 2: Enter a message to send: ");
        fgets(write_msg, sizeof(write_msg), stdin);

        write(fd_write, write_msg, strlen(write_msg) + 1);
        printf("Program 2: Sent message: %s", write_msg);
    }

    close(fd_read);
    close(fd_write);

    return 0;
}


/*
============================================================================
Output:
    Program 2: Received message: Hi program 2

    Program 2: Enter a message to send: Hello program 1
    Program 2: Sent message: Hello program 1
    Program 2: Received message: bye

    Program 2: Enter a message to send: ok bye
    Program 2: Sent message: ok bye
    Program 2: Received message: bye
============================================================================
*/