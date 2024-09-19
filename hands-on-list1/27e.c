/*
============================================================================
Name : 27e.c
Author : Shatakshee Mishra
Description : Write a program to execute ls -Rl by the following system calls
e. execvp
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main()
{char *path = "ls";
 char *argv[] = {path, "-Rl", NULL};
 execvp(path, argv);
}
