/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/

/*Write a program to create a file and print the file descriptor value.
 Use creat ( ) system call*/
#include <fcntl.h>
#include <stdio.h>
int main (void){
printf ("fd =%d\n" , creat("myfile",0744));
}
