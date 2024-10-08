/*
============================================================================
Name : 13.c
Author : Shatakshee Mishra
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 18th Aug, 2024.
============================================================================
*/

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


