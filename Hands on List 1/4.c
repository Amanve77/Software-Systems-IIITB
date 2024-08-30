/*
============================================================================
Name : 4.c
Author : Aman Verma
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main() 
{

	int fd = open("3.txt", O_RDWR | O_EXCL);

	if(fd == -1) 
       	perror("Failed to open file");
	else
        printf("File opened successfully. File descriptor: %d\n", fd);
        
	close(fd);

	return 0;
}
/*
============================================================================
Output:
	File opened successfully. File descriptor: 3
============================================================================
*/