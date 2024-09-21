/*
============================================================================
Name : 22a.c
Author : Shatakshee Mishra
Description :Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21st Sep, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>  
#include <fcntl.h>     
#include <sys/time.h>  
#include <unistd.h>    
#include <stdio.h>     

void main()
{
struct timeval t;
fd_set fd;
char *path = "./22-fifo";
mkfifo(path, S_IRWXU);
int f = open(path, O_NONBLOCK | O_RDONLY);
FD_ZERO(&fd);
FD_SET(f, &fd);
t.tv_sec = 5;
t.tv_usec = 0;
int o = select(f + 1, &fd, NULL, NULL, &t);
if (o == 0)
{
printf("Time out");
}
else
{
char buf;
while (read(f, &buf, 1) > 0)
write(1, &buf, 1);
write(1, "\n", 1);
}
close(f);
}
