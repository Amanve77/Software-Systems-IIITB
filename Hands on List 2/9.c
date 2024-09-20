/*
============================================================================
Name : 9.c
Author : Aman Verma
Description :  Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.  
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void reset_sigint(int signum) 
{
    printf("\nSIGINT received but ignored. Resetting to default behavior.\n");
    signal(SIGINT, SIG_DFL);
}

int main() 
{
    signal(SIGINT, SIG_IGN);
    printf("SIGINT signal is being ignored for 5 seconds. Try pressing Ctrl+C...\n");
    
    sleep(5);

    signal(SIGINT, reset_sigint);
    printf("Now, SIGINT signal will be caught once. Press Ctrl+C...\n");
    
    while (1)
        pause();  

    return 0;
}


/*
============================================================================
Output:
    SIGINT signal is being ignored for 5 seconds. Try pressing Ctrl+C...
    ^CNow, SIGINT signal will be caught once. Press Ctrl+C...
    ^C
    SIGINT received but ignored. Resetting to default behavior.
    ^C
============================================================================
*/