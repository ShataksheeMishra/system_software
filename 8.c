/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/
/*. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int  main (void)
{int fd,w ;
char buff[1024];
fd = open("8_source",O_RDONLY);
while(read (fd,buff,1))
{
	if(buff[0]=='\n')
	getchar();
	else 
	 w= write(0,buff,1);



}
}
