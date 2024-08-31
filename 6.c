/*
============================================================================
Name : 6.c
Author : Shatakshee Mishra
Description : *Write a program to take input from STDIN and display on STDOUT.
 Use only read/write system calls.
Date: 8th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main (void)
{
char buffer[80];
read (0, buffer , sizeof(buffer));  
write (1,buffer, sizeof(buffer) );
}

/*output
shatakshee@shatakshee:~/ss$ ./a.out
hello
hello
*/
