/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/

/*Write a program to take input from STDIN and display on STDOUT.
 Use only read/write system calls. */
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main (void)
{
char buffer[80];
read (0, buffer , sizeof(buffer));  
write (1,buffer, sizeof(buffer) );
}
