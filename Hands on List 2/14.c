/*
============================================================================
Name : 14.c
Author : Aman Verma
Description :  Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.  
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() 
{
    int pipefds[2];
    char write_msg[] = "Hello from the pipe!";
    char read_msg[100];

    if (pipe(pipefds) == -1) 
    {
        perror("pipe");
        return 1;
    }

    write(pipefds[1], write_msg, strlen(write_msg) + 1);

    read(pipefds[0], read_msg, sizeof(read_msg));

    printf("Read from pipe: %s\n", read_msg);

    close(pipefds[0]);
    close(pipefds[1]);

    return 0;
}



/*
============================================================================
Output:
    Read from pipe: Hello from the pipe!
============================================================================
*/