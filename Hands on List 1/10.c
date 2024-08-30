/*
============================================================================
Name : 10.c
Author : Aman Verma
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
                a. check the return value of lseek
                b. open the file with od and check the empty spaces in between the data. 
Date: 30th Aug, 2024.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    const char *filename = "file10";
    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if(fd == -1)
    {
        perror("open");
        return 1;
    }
    const char *data = "1234567890";
    if(write(fd, data, 10) == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }

    off_t offset = lseek(fd, 10, SEEK_CUR);
    if(offset == -1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }
    else
        printf("lseek() moved to pointer : %ld\n", offset);
    const char *data2 = "asdfghjklt";
    if(write(fd, data2, 10) == -1)
    {
        perror("write");
        return 1;
    }

    close(fd);
    printf("File written successfuly");


    return 0;
}
/*
============================================================================
Output:
    Output of Program:
        lseek() moved to pointer : 20
        File written successfuly
        
    Output of opening file with od:
        0000000   1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
        0000020  \0  \0  \0  \0   a   s   d   f   g   h   j   k   l   t
        0000036
============================================================================
*/