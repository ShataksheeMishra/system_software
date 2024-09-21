/*
============================================================================
Name : 22b.c
Author : Shatakshee Mishra
Description :Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21st Sep, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
int f;
char *s = "./22-fifo";
mkfifo(s, S_IRWXU);
f = open(s, O_NONBLOCK | O_WRONLY);
char *st;
long int size=100;
printf("enter message\n");
int l=getline(&st,&size,stdin);
write(f, st, l);
close(f);
}
