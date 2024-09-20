/*
============================================================================
Name : 19e.c
Author : Aman Verma
Description :  Create a FIFO file by
                    e. mkfifo library function 
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() 
{
    const char *fifo_path = "fifo_file1";

    if (mkfifo(fifo_path, 0666) == -1) 
    {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("FIFO file created with mkfifo.\n");
    return 0;
}


/*
============================================================================
Output:
    FIFO file created with mkfifo.
============================================================================
*/