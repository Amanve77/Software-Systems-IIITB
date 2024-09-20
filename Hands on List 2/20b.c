/*
============================================================================
Name : 20b.c
Author : Aman Verma
Description :  Write two programs so that both can communicate by FIFO -Use one way communication  
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_FILE "fifo_file1"

int main() 
{
    int fd;
    char buffer[800];

    fd = open(FIFO_FILE, O_RDONLY);
    if (fd == -1) 
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) 
    {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }

    buffer[bytesRead] = '\0';
    printf("Message read from FIFO: %s", buffer);

    close(fd);
    return 0;
}


/*
============================================================================
Output:
    Message read from FIFO: Hello from the writer program!
============================================================================
*/