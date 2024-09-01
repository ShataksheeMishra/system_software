/*
============================================================================
Name : 1c.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 8th Aug, 2024.
============================================================================
*/

#include <sys/stat.h>
#include<stdio.h>
#include <unistd.h>

int main(){
char *path="fifofile";
if((mknod(path,0744,0)==-1))
{perror("error");}
printf("success");
}

