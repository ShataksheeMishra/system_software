/*
============================================================================
Name : 20b.c
Author : Shatakshee Mishra
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
char buff[80];
int fd = open("file20", O_RDONLY);
read(fd, buff, sizeof(buff));
printf("Received message: %s", buff);
close(fd);
return 0;
}
