/*
============================================================================
Name : 21.c
Author : Shatakshee Mishra
Description : Write a program, call fork and print the parent and child process id.
Date: 30th Aug, 2024.
============================================================================
*/

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

