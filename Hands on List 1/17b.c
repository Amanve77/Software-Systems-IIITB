/*
============================================================================
Name : 17b.c
Author : Aman Verma
Description : Write a program to simulate online ticket reservation. Implement write lock.Write a program to open a file, 
              store a ticket number and exit. Write a separate program, to open the file, implement write lock, 
              read the ticket number, increment the number and print the new ticket number then close the file.
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() 
{
    int fd;
    struct flock lock;
    char ticket_number[12];
    int current_ticket_number;

    const char *filename = "tickets.txt";

    fd = open(filename, O_RDWR, 0644);
    if (fd == -1) 
    {
        perror("open");
        exit(1);
    }

    lock.l_type = F_WRLCK; 

    if (fcntl(fd, F_SETLKW, &lock) == -1) 
    {
        perror("write lock");
        exit(EXIT_FAILURE);
    }

    if (read(fd, ticket_number, 11) == -1) 
    {
        perror("read");
        exit(1);
    }

    ticket_number[12] = '\0';
    current_ticket_number = atoi(ticket_number);
    current_ticket_number++;

    snprintf(ticket_number, sizeof(ticket_number), "%d", current_ticket_number);

    if (lseek(fd, 0, SEEK_SET) == -1) 
    {
        perror("lseek");
        exit(1);
    }

    if (write(fd, ticket_number, strlen(ticket_number)) == -1) 
    {
        perror("write");
        exit(1);
    }

    printf("New ticket number: %s\n", ticket_number);

    lock.l_type = F_UNLCK; 
    if (fcntl(fd, F_SETLK, &lock) == -1) 
    {
        perror("unlock");
        exit(1);
    }

    close(fd);

    return 0;
}
/*
============================================================================
Output:
    New ticket number: 1234567892
============================================================================
*/