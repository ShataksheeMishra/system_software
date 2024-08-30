/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/
/*Write a program to display the environmental variable of the user (use environ).*/
#include<stdio.h>
int main(void)
{extern char **environ;

int i=0;
while (environ[i]!=NULL)
printf("%s \n",environ[i++]);
return 0;

}
