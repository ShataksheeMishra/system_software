/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/

/*Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main (void)
{
int fd;
fd = open ("file2" , O_CREAT | O_RDWR , 0744);
write (fd, " Hello everyone\n" , 16);
lseek(fd, 10L, SEEK_SET);
write (fd, " I am Shatakshee Mishra\n", 24);
close (fd);
}
