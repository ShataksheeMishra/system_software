/*
============================================================================
Name : 21b.c
Author : Shatakshee Mishra
Description : Write two programs so that both can communicate by FIFO -Use two way communication.
Date: 21st Sep, 2024.
============================================================================
*/#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
char buffer[100];
mkfifo("file21a", 0666);
mkfifo("file21b", 0666);
int read_fd = open("file21a", O_RDONLY);
int write_fd = open("file21b", O_WRONLY);

while (1) {
read(read_fd, buffer, sizeof(buffer));
printf("file21a says: %s", buffer);
if (strncmp(buffer, "exit", 4) == 0) {
break;
 }
printf("file21b: Enter a message: ");
fgets(buffer, sizeof(buffer), stdin);
write(write_fd, buffer, strlen(buffer) + 1);
if (strncmp(buffer, "exit", 4) == 0) {
break;
}
}
close(write_fd);
close(read_fd);
return 0;
}
