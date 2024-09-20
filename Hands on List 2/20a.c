/*
============================================================================
Name : 20a.c
Author : Aman Verma
Description :  Write two programs so that both can communicate by FIFO -Use one way communication  
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "fifo_file1"

int main() 
{
    int fd;
    const char *message = "Hello from the writer program!\n";

    fd = open(FIFO_FILE, O_WRONLY);
    if (fd == -1) 
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (write(fd, message, strlen(message)) == -1) 
    {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Message written to FIFO.\n");

    close(fd);
    return 0;
}


/*
============================================================================
Output:
    Message written to FIFO.
============================================================================
*/