/*
============================================================================
Name : 11.c
Author : Aman Verma
Description :  Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call. 
Date: 18th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void reset_sigint_handler(int signum) 
{
    printf("\nSIGINT received but ignored. Resetting to default behavior...\n");
    
    struct sigaction sa;
    sa.sa_handler = SIG_DFL;  
    sigaction(SIGINT, &sa, NULL); 
}

int main() 
{
    struct sigaction sa;

    sa.sa_handler = SIG_IGN; 
    sigaction(SIGINT, &sa, NULL); 
    printf("SIGINT is being ignored for 5 seconds. Try pressing Ctrl+C...\n");

    sleep(5);  

    sa.sa_handler = reset_sigint_handler;
    sigaction(SIGINT, &sa, NULL); 

    printf("SIGINT will now be caught once, and reset to default. Press Ctrl+C...\n");

    while (1) {
        pause(); 
    }

    return 0;
}


/*
============================================================================
Output:
    SIGINT is being ignored for 5 seconds. Try pressing Ctrl+C...
    ^C^CSIGINT will now be caught once, and reset to default. Press Ctrl+C...
    ^C
    SIGINT received but ignored. Resetting to default behavior...
    ^C
============================================================================
*/