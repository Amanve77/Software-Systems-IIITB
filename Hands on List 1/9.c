/*
============================================================================
Name : 9.c
Author : Aman Verma
Description : Write a program to print the following information about a given file.
				a. inode
				b. number of hard links
				c. uid
				d. gid
				e. size
				f. block size
				g. number of blocks
				h. time of last access
				i. time of last modification
				j. time of last change
Date: 30th Aug, 2024.
============================================================================
*/



#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("give correct arguments");
		return 1;
	}

	struct stat file_stat;
	
	if(stat(argv[1], &file_stat) == -1)
	{
		perror("stat");
		printf("error");
		return 1;
	}

	printf("File : %s\n", argv[1]);
	printf("Inode : %ld\n", (long)file_stat.st_ino);
	printf("Number of hard links: %ld\n", (long)file_stat.st_nlink);
    printf("User ID (UID): %ld\n", (long)file_stat.st_uid);
    printf("Group ID (GID): %ld\n", (long)file_stat.st_gid);
    printf("Size: %ld bytes\n", (long)file_stat.st_size);
    printf("Block size: %ld bytes\n", (long)file_stat.st_blksize);
    printf("Number of blocks: %ld\n", (long)file_stat.st_blocks);
	printf("Time of last access: %s", ctime(&file_stat.st_atime));
	printf("Time of last modification: %s", ctime(&file_stat.st_mtime));
    printf("Time of last status change: %s", ctime(&file_stat.st_ctime));
	
	return 0;

}

/*
============================================================================
Output:
	File : file8
	Inode : 5116480
	Number of hard links: 1
	User ID (UID): 1000
	Group ID (GID): 1000
	Size: 27 bytes
	Block size: 4096 bytes
	Number of blocks: 8
	Time of last access: Sat Aug 31 00:35:40 2024
	Time of last modification: Sat Aug 31 00:35:38 2024
	Time of last status change: Sat Aug 31 00:35:38 2024
============================================================================
*/