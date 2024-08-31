/*
============================================================================
Name : 26a.c
Author : Shatakshee Mishra
Description : Write a program to execute an executable program.
a. use some executable program
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int arg, char* argv[]) {
        execv(argv[1], &argv[1]);
        return 0;
}
