/*
============================================================================
Name : 16.c
Author : Aman Verma
Description : Write a program to perform mandatory locking.
                a. Implement write lock
                b. Implement read lock 
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int fd;
    struct flock lock;

    fd = open("16.txt", O_RDWR , 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    lock.l_type = F_WRLCK;         
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("write lock");
        close(fd);
        return 1;
    }
    printf("Write lock applied\n");
    
    lock.l_type = F_RDLCK;    
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("read lock");
        close(fd);
        return 1;
    }
    printf("Read lock applied\n");
    sleep(20);
    close(fd);

    return 0;
}
/*
============================================================================
Output:
    Write lock applied
    Read lock applied

Output when trying to lock file in different terminal while above program is running:
    write lock: Resource temporarily unavailable
============================================================================
*/