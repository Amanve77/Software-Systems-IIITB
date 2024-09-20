/*
============================================================================
Name : 19d.c
Author : Aman Verma
Description :  Create a FIFO file by
                    d. mknod system call
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


int main() 
{
    const char *fifo_path = "fifo_file";

    if (mknod(fifo_path, S_IFIFO | 0666, 0) == -1) 
    {
        perror("mknod");
        exit(EXIT_FAILURE);
    }

    printf("FIFO file created with mknod.\n");
    return 0;
}


/*
============================================================================
Output:
    FIFO file created with mknod.
============================================================================
*/