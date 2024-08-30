/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/

/*Write a program to open an existing file with read write mode. Try O_EXCL flag also.*/
#include <stdio.h>
#include <fcntl.h>
int main (void){ 
int fd,fd1;
fd =  open("foods" , O_RDWR);
fd1 =open("foods" , O_RDWR|O_EXCL|O_CREAT,0744); 
printf("fd= %d,%d\n",fd,fd1);
}
