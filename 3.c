/*
============================================================================
Name : 3.c
Author : Shatakshee Mishra
Description : Write a program to create a file and print the file descriptor value.
 Use creat ( ) system call
Date: 8th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
int main (void){
printf ("fd =%d\n" , creat("myfile",0744));
}
