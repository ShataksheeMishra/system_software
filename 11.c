/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/
/*Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main (void)
{
int  fd1, fd2,fd3, fd4;
fd1=open("foods",O_RDWR);
fd2=dup(fd1);
dup2(fd1, fd3);
fd4=fcntl(fd1,F_DUPFD);
printf("fd1=%d\n fd2=%d\n fd3=%d\n fd4=%d\n ", fd1,fd2,fd3,fd4);
}
