/*
============================================================================
Name : 12.c
Author : Aman Verma
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("give proper filename");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY | O_APPEND, 0644);
    if(fd == -1)
    {
        perror("open");
        close(fd);
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);

    int access_mode = flags & O_ACCMODE;
    switch (access_mode)
    {
    case O_RDONLY : printf("File is opened in read-only mode\n");
                    break;
    case O_WRONLY : printf("File is opened in write-only mode\n");
                    break;
    case O_RDWR : printf("File is opened in read-write mode\n");
                    break;
    default: printf("File is opened in unknown access mode\n");
        break;
    }

    if (flags & O_APPEND)
        printf("File is opened in O_APPEND mode\n");
    if(flags & O_SYNC)
        printf("File is opened in O_SYNC mode\n");
    if (flags & O_NONBLOCK)
        printf("File is opened in O_NONBLOCK mode\n");
    if (flags & O_CREAT)
        printf("File is opened in O_CREAT mode\n");
    if (flags & O_TRUNC)
        printf("File is opened in O_TRUNC mode\n");


    close(fd);

    return 0;
}
/*
============================================================================
Output:
    File is opened in read-only mode
    File is opened in O_APPEND mode
============================================================================
*/