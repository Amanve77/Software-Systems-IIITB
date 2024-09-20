/*
============================================================================
Name : 22.c
Author : Aman Verma
Description :  Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.  
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main() 
{
    int fifo_fd;
    char buffer[100];
    fd_set read_fds;
    struct timeval timeout;
    int retval;

    if (mkfifo("myfifo", 0666) == -1) 
    {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    fifo_fd = open("myfifo", O_RDONLY | O_NONBLOCK);
    if (fifo_fd == -1) 
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    FD_ZERO(&read_fds);
    FD_SET(fifo_fd, &read_fds);

    printf("Waiting for data in FIFO, will timeout after 10 seconds if no data...\n");

    retval = select(fifo_fd + 1, &read_fds, NULL, NULL, &timeout);

    if (retval == -1) 
    {
        perror("select");
        close(fifo_fd);
        exit(EXIT_FAILURE);
    } else if (retval == 0) 
    {

        printf("No data received in 10 seconds. Exiting...\n");
    } 
    else 
    {

        if (FD_ISSET(fifo_fd, &read_fds)) 
        {
            int bytes_read = read(fifo_fd, buffer, sizeof(buffer));
            if (bytes_read > 0) 
            {
                buffer[bytes_read] = '\0'; 
                printf("Received data: %s\n", buffer);
            } 
            else 
            {
                printf("Error reading from FIFO or no data available.\n");
            }
        }
    }

    close(fifo_fd);
    unlink("myfifo");

    return 0;
}


/*
============================================================================
Output:
    Waiting for data in FIFO, will timeout after 10 seconds if no data...
    Received data: Hello from another terminal!
============================================================================
*/