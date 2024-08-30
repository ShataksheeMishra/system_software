/*Write a program to execute ls -Rl by the following system calls
a. execl*/
#include<stdio.h>
#include<unistd.h>
int main(void)
{
execl("/bin/ls","ls","-rl",NULL);
} 
