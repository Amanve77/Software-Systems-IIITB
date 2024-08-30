/*
============================================================================
Name : 13.c
Author : Aman Verma
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    struct timeval timeout;

    FD_SET(0, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int retval = select(1, &readfds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select()");
        return 1;

    } 
    else if (retval) 
    {
        printf("Data is available on STDIN!\n");
        char buffer[128];
        ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) 
            printf("You entered: %s", buffer);
        else 
            perror("read()");
    } 
    else 
        printf("No data within 10 seconds.");

    return 0;
}
/*
============================================================================
Output:
    This is program 13
    Data is available on STDIN!
    You entered: This is program 13
============================================================================
*/