/*
============================================================================
Name : 27a.c
Author : Shatakshee Mishra
Description : Write a program to execute ls -Rl by the following system calls
a. execl
Date: 30th Aug, 2024.
============================================================================
*/
/*Write a program to execute ls -Rl by the following system calls
a. execl*/
#include<stdio.h>
#include<unistd.h>
int main(void)
{
execl("/bin/ls","ls","-rl",NULL);
} 
