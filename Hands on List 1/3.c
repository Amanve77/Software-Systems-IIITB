/*
============================================================================
Name : 3.c
Author : Aman Verma
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 30th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main() 
{

	int fd = creat("3.txt", 0644);

	if(fd < -1) 
	{
		perror("Error in file creation");
		return 1;
	}
	printf("File descriptor = %d", fd);
	close(fd);

	return 0;

}

/*
============================================================================
Output:
	File descriptor = 3
============================================================================
*/
