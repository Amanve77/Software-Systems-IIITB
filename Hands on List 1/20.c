/*
============================================================================
Name : 20.c
Author : Aman Verma
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("Running program with PID: %d\n", getpid());
        sleep(2);
    }
    return 0;
}


/*
============================================================================
Output: 
    Before changing priority:
        PID  NI
        7329   0
    After changing priority:
        PID  NI
        7329   0
============================================================================
*/
