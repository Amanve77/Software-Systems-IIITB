/*
============================================================================
Name : 17a.c
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
#include <string.h>

int main() {
    int fd;
    const char *filename = "tickets.txt";
    const char *initial_ticket_number = "1234567891";

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (write(fd, initial_ticket_number, strlen(initial_ticket_number)) == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Initial ticket number written to the file.\n");
    close(fd);

    return 0;
}
/*
============================================================================
Output:
    Initial ticket number written to the file.
============================================================================
*/