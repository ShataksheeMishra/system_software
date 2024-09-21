/*
============================================================================
Name : 19e.c
Author : Shatakshee Mishra
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 21st Sep, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
int main() {
mkfifo("myfifo_e", 0666);
printf("FIFO file created.\n");
return 0;
}
