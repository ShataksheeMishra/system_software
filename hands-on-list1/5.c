/*
============================================================================
Name : 5.c
Author : Shatakshee Mishra
Description : Write a program to create five new files with infinite loop. Execute the program
 in the background and check the file descriptor table at /proc/pid/fd.

Date: 8th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
int main(void)
{int fd1,fd2,fd3,fd4,fd5;
fd1=open("f1", O_CREAT|O_RDWR,0764);
fd2=open("f2", O_CREAT|O_RDWR,0764);
fd3=open("f3", O_CREAT|O_RDWR,0764);
fd4=open("f4", O_CREAT|O_RDWR,0764);
fd5=open("f5", O_CREAT|O_RDWR,0764);
for (;;);
}


/*output
shatakshee@shatakshee:/proc/5353/fd$ ll
total 0
dr-x------ 2 shatakshee shatakshee  8 Aug 31 12:57 ./
dr-xr-xr-x 9 shatakshee shatakshee  0 Aug 31 12:57 ../
lrwx------ 1 shatakshee shatakshee 64 Aug 31 12:57 0 -> /dev/pts/1
lrwx------ 1 shatakshee shatakshee 64 Aug 31 12:57 1 -> /dev/pts/1
lrwx------ 1 shatakshee shatakshee 64 Aug 31 12:57 2 -> /dev/pts/1
lrwx------ 1 shatakshee shatakshee 64 Aug 31 12:57 3 -> /home/shatakshee/ss/f1*
lrwx------ 1 shatakshee shatakshee 64 Aug 31 12:57 4 -> /home/shatakshee/ss/f2*
lrwx------ 1 shatakshee shatakshee 64 Aug 31 12:57 5 -> /home/shatakshee/ss/f3*
lrwx------ 1 shatakshee shatakshee 64 Aug 31 12:57 6 -> /home/shatakshee/ss/f4*
lrwx------ 1 shatakshee shatakshee 64 Aug 31 12:57 7 -> /home/shatakshee/ss/f5*
*/
