/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/

/*Write a program, call fork and print the parent and child process id.*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
int main()
{if(fork())
printf("parent pid =%d\n",getpid());
else
printf("child pid=%d\n",getpid());}

//output
/*
shatakshee@shatakshee:~/ss$ nano 21.c
shatakshee@shatakshee:~/ss$ cc 21.c
shatakshee@shatakshee:~/ss$ ./a.out &
[1] 7133
shatakshee@shatakshee:~/ss$ parent pid =7133
child pid=7134
*/

