/*
============================================================================
Name : 14.c
Author : Aman Verma
Description : Write a program to find the type of a file.
                a. Input should be taken from command line.
                b. program should be able to identify any type of a file. 
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    struct stat file_stat;

    if (argc != 2) 
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (lstat(argv[1], &file_stat) == -1) 
    {
        perror("stat");
        return 1;
    }

    if (S_ISREG(file_stat.st_mode)) 
        printf("File type: Regular file\n");
    else if (S_ISDIR(file_stat.st_mode)) 
        printf("File type: Directory\n");
    else if (S_ISLNK(file_stat.st_mode)) 
        printf("File type: Symbolic link\n");
    else if (S_ISCHR(file_stat.st_mode)) 
        printf("File type: Character device\n");
    else if (S_ISBLK(file_stat.st_mode)) 
        printf("File type: Block device\n");
    else if (S_ISFIFO(file_stat.st_mode)) 
        printf("File type: FIFO (named pipe)\n");
    else if (S_ISSOCK(file_stat.st_mode)) 
        printf("File type: Socket\n");
    else 
        printf("File type: Unknown\n");

    return 0;
}
/*
============================================================================
Output:
    File type: Regular file
============================================================================
*/