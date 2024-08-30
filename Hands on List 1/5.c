/*
============================================================================
Name : 5.c
Author : Aman Verma
Description : Write a program to create five new files with infinite loop. 
			  Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main() 
{
	int count = 1;
	char filename[256];
	pid_t pid = getpid();
	printf("Process ID: %d\n", pid);
	while(1)
	{
		snprintf(filename, sizeof(filename), "file_%d.txt", count);
		if(count <= 5)
		{
			int fd = open(filename, O_CREAT | O_RDWR, 0666);
			if(fd == -1)
			{
				perror("Failed to open file_%d" + count);
				exit(1);
			}
			printf("Opened file_%d with file descriptor: %d\n", count, fd);
			sleep(10);
			close(fd);
			count++;	 
		}
	}
	return 0;
}

/*
============================================================================
Output:
	Process ID: 13043
	Opened file_1 with file descriptor: 3
	Opened file_2 with file descriptor: 3
	Opened file_3 with file descriptor: 3
	Opened file_4 with file descriptor: 3
	Opened file_5 with file descriptor: 3
============================================================================
*/
