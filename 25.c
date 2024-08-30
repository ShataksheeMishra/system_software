/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/

/*Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){
int i,j,k;
if (!(i=fork()))
	sleep(2);
else if(!(j=fork()))
	sleep(3);
else if(!(k=fork()))
	sleep(4);
else
	waitpid(j,NULL,0);
}

