/*
============================================================================
Name : 23.c
Author : Shatakshee Mishra
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 21st Sep, 2024.
============================================================================
*/#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>
void main()
{
long maxFile;
long pipesize; 
char *s = "23_fifo";
mkfifo(s, S_IRWXU);
maxFile = sysconf(_SC_OPEN_MAX);
printf("Maximum number of files that can be opened is: %ld\n", maxFile);
printf(" Size of pipe: %d\n", PIPE_BUF);
}
