/*
============================================================================
Name : 26.c
Author : Aman Verma
Description : Write a program to execute an executable program.
                a. use some executable program
                b. pass some input to an executable program. (for example execute an executable of $./a.out name) 
Date: 31th Aug, 2024.
============================================================================
*/

#include <unistd.h>

int main()
{
    char *executable_path = "./q14";
    char *arg = "file1";

    execl(executable_path, executable_path, arg, NULL);

    return 0;
}

/*
============================================================================
Output:
    File type: Regular file
============================================================================
*/