/*
============================================================================
Name : 27d.c
Author : Aman Verma
Description : Write a program to execute ls -Rl by the following system calls
                d. execv
Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    char *args[] = { "ls", "-Rl", NULL };
    if (execv("/bin/ls", args) == -1) 
    {
        perror("execv failed");
        exit(0);
    }

    return 0;
}
/*
============================================================================
Output:
    .:
    total 200
    -rw-rw-r-- 1 aman-verma aman-verma  1661 Aug 31 02:09 10.c
    -rw-rw-r-- 1 aman-verma aman-verma  2127 Aug 31 02:09 11.c
    -rw-rw-r-- 1 aman-verma aman-verma  1630 Aug 31 02:09 12.c
    -rw-rw-r-- 1 aman-verma aman-verma  1243 Aug 31 02:09 13.c
    -rw-rw-r-- 1 aman-verma aman-verma  1450 Aug 31 02:09 14.c
    -rw-rw-r-- 1 aman-verma aman-verma  5616 Aug 31 02:09 15.c
    -rw-rw-r-- 1 aman-verma aman-verma  1227 Aug 31 02:09 16.c
    -rw-rw-r-- 1 aman-verma aman-verma     0 Aug 31 01:33 16.txt
    -rw-rw-r-- 1 aman-verma aman-verma  1218 Aug 31 02:31 17a.c
    -rw-rw-r-- 1 aman-verma aman-verma  1852 Aug 31 02:09 17b.c
    -rw-rw-r-- 1 aman-verma aman-verma   809 Aug 31 02:09 19.c
    -rw-rw-r-- 1 aman-verma aman-verma   307 Aug 31 02:12 1_b.c
    -rw-rw-r-- 1 aman-verma aman-verma   632 Aug 31 02:08 1a.c
    -rw-rw-r-- 1 aman-verma aman-verma   702 Aug 31 02:12 1b.c
    -rw-rw-r-- 1 aman-verma aman-verma   649 Aug 31 02:09 1c.c
    -rw-rw-r-- 1 aman-verma aman-verma  2173 Aug 31 02:09 2.c
    -rw-rw-r-- 1 aman-verma aman-verma   627 Aug 31 02:09 20.c
    -rw-rw-r-- 1 aman-verma aman-verma   811 Aug 31 02:09 21.c
    -rw-rw-r-- 1 aman-verma aman-verma  1375 Aug 31 02:09 22.c
    -rw-rw-r-- 1 aman-verma aman-verma  1371 Aug 31 02:09 23.c
    -rw-rw-r-- 1 aman-verma aman-verma  1136 Aug 31 02:09 24.c
    -rw-rw-r-- 1 aman-verma aman-verma  2274 Aug 31 13:19 25.c
    -rw-rw-r-- 1 aman-verma aman-verma   793 Aug 31 13:27 26.c
    -rw-rw-r-- 1 aman-verma aman-verma  1244 Aug 31 13:36 27.c
    -rw-rw-r-- 1 aman-verma aman-verma   597 Aug 31 02:09 3.c
    -rw-r--r-- 1 aman-verma aman-verma     0 Aug 31 00:05 3.txt
    -rw-rw-r-- 1 aman-verma aman-verma   676 Aug 31 02:09 4.c
    -rw-rw-r-- 1 aman-verma aman-verma  1164 Aug 31 02:09 5.c
    -rw-rw-r-- 1 aman-verma aman-verma   583 Aug 31 02:09 6.c
    -rw-rw-r-- 1 aman-verma aman-verma  1035 Aug 31 02:09 7.c
    -rw-rw-r-- 1 aman-verma aman-verma   902 Aug 31 02:09 8.c
    -rw-rw-r-- 1 aman-verma aman-verma  1822 Aug 31 02:09 9.c
    -rwxrwxr-x 1 aman-verma aman-verma 16096 Aug 31 13:36 a.out
    -rw-rw-r-- 2 aman-verma aman-verma    21 Aug 31 00:25 file1
    -rw-r--r-- 1 aman-verma aman-verma    30 Aug 31 00:51 file10
    -rw-r--r-- 1 aman-verma aman-verma   123 Aug 31 00:58 file11
    -rw-rw-r-- 2 aman-verma aman-verma    21 Aug 31 00:25 file1_hard_link
    lrwxrwxrwx 1 aman-verma aman-verma     5 Aug 30 23:43 file1_soft_link -> file1
    -rw------- 1 aman-verma aman-verma    21 Aug 31 00:30 file7
    -rw-rw-r-- 1 aman-verma aman-verma    27 Aug 31 00:35 file8
    -rw-rw-r-- 1 aman-verma aman-verma     0 Aug 31 00:14 file_1.txt
    -rw-rw-r-- 1 aman-verma aman-verma     0 Aug 31 00:14 file_2.txt
    -rw-rw-r-- 1 aman-verma aman-verma     0 Aug 31 00:14 file_3.txt
    -rw-rw-r-- 1 aman-verma aman-verma     0 Aug 31 00:14 file_4.txt
    -rw-rw-r-- 1 aman-verma aman-verma     0 Aug 31 00:15 file_5.txt
    prw-rw-r-- 1 aman-verma aman-verma     0 Aug 31 02:02 myfifo
    -rwxrwxr-x 1 aman-verma aman-verma 16136 Aug 31 13:22 q14
    -rwxrwxr-x 1 aman-verma aman-verma 15960 Aug 30 23:59 q2
    -rw-r--r-- 1 aman-verma aman-verma    10 Aug 31 02:31 tickets.txt
============================================================================
*/