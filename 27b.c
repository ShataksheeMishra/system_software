/*Write a program to execute ls -Rl by the following system calls
b.execlp*/
#include<stdio.h>
#include<unistd.h>
int main(void)
{
execlp("/bin/ls","ls","-rl",NULL);
} 
