/*
============================================================================
Name : 22.c
Author : Aman Verma
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.  
Date: 30th Aug, 2024.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    int fd;
    pid_t pid;

    fd = open("22.txt", O_WRONLY | O_CREAT , 0644);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    pid = fork();

    if(pid < 0) 
    {
        perror("fork failed");
        close(fd);
        return 1;
    } 
    else if(pid == 0) 
    {
        const char *child_msg = "This is the child process writing to the file.\n";
        write(fd, child_msg, strlen(child_msg));
        printf("Child process wrote to the file.\n");
    } 
    else 
    {
        const char *parent_msg = "This is the parent process writing to the file.\n";
        write(fd, parent_msg, strlen(parent_msg));
        printf("Parent process wrote to the file.\n");
    }

    close(fd);

    return 0;
}


/*
============================================================================
Output:
    Parent process wrote to the file.
    Child process wrote to the file.
============================================================================
*/