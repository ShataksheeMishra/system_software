/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/

/*Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/select.h>
int main (void)
{
fd_set fds;
struct timeval tv;
int retval;

FD_ZERO(&fds);
FD_SET(0,&fds);
tv.tv_sec=10;
retval = select(1,&fds,NULL,NULL,&tv);
if (retval)
	printf("data is availabe within 10 sec\n");
else
	printf("data is not available within 10 sec\n");
}


