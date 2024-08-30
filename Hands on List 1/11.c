/*
============================================================================
Name : 11.c
Author : Aman Verma
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
                a. use dup
                b. use dup2
                c. use fcntl
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd, dup_fd, dup2_fd, fcntl_fd;
    char const *filename = "file11";
    char const *message = "Written with original descriptor. ";
    char const *message_dup = "Written with dup descriptor. ";
    char const *message_dup2 = "Written with dup2 descriptor. ";
    char const *message_fcntl = "Written with fcntl descriptor.";

    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if(fd == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }
    write(fd, message, strlen(message));

    dup_fd = dup(fd);
    if(dup_fd == -1)
    {
        perror("write");
        close(fd);
        close(dup_fd);
        return 1;
    }
    write(dup_fd, message_dup, strlen(message_dup));

    dup2_fd = dup2(fd, 10);
    if(dup2_fd == -1)
    {
        perror("write");
        close(fd);
        close(dup_fd);
        close(dup2_fd);
        return 1;
    }
    write(dup2_fd, message_dup2, strlen(message_dup2));

    fcntl_fd = fcntl(fd, F_DUPFD, 0);
    if(fcntl_fd == -1)
    {
        perror("write");
        close(fd);
        close(dup_fd);
        close(dup2_fd);
        close(fcntl_fd);
        return 1;
    }
    write(fcntl_fd, message_fcntl, strlen(message_fcntl));

    close(fd);
    close(dup_fd);
    close(dup2_fd);
    close(fcntl_fd);

    printf("File updated successfully");

    return 0;
}

/*
============================================================================
Output:
    File updated successfully

File11 Data:
    Written with original descriptor. Written with dup descriptor. Written with dup2 descriptor. Written with fcntl descriptor.
============================================================================
*/