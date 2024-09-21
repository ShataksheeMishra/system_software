/*
============================================================================
Name : 19a.c
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

#include <stdio.h>
#include <stdlib.h>

int main() {
system("mknod myfifo_a p");
printf("FIFO file is created.\n");
return 0;
}
