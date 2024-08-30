/*
============================================================================
Name : 6.c
Author : Aman Verma
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 30th Aug, 2024.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
	char buffer[32];
	int sie_read = read(0, buffer, 10);
	printf("%d\n", sie_read);
	fflush(stdout);
	write(1, buffer, sie_read);
	return 0;
}

/*
============================================================================
Output:
	Question 6
	10
	Question 6
============================================================================
*/