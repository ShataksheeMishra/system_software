/*
============================================================================
Name : 27c.c
Author : Shatakshee Mishra
Description : Write a program to execute ls -Rl by the following system calls
c. execv
Date: 30th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main(void)
{char *path ="/bin/ls";
char *argv[]={path,"-Rl",NULL};
execv(path,argv);
} 
