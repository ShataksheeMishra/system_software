/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main (void){
int fd;
char buff[80];
fd=open("myfifo", O_WRONLY);
printf("enter name:");
scanf("%[^\n]",buff);
write(fd,buff,sizeof(buff));
}
