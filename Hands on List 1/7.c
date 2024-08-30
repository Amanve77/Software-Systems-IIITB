/*
============================================================================
Name : 7.c
Author : Aman Verma
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 30th Aug, 2024.
============================================================================
*/


#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char * argv[]) 
{
        int file1 = open(argv[1], O_RDONLY);
        if(file1 < 0) 
        {
                perror("Program1");
                exit(0);
        }
        int file2 = open(argv[2], O_WRONLY | O_EXCL | O_CREAT, 0600);
        if(file2 < 0) 
        {
                perror("Program2");
                exit(0);
        }

        char buffer[1024];
        int size_read;
        while((size_read = read(file1, buffer, sizeof(buffer))) > 0) 
                write(file2, buffer, size_read);
                
        close(file1);
        close(file2);
	printf("Success");
	return 0;
}
/*
============================================================================
Output:
        Success
============================================================================
*/