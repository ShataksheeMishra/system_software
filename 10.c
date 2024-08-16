#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main (void)
{
int fd;
fd = open ("file2" , O_CREAT | O_RDWR , 0744);
write (fd, " Hello everyone\n" , 16);
lseek(fd, 10L, SEEK_SET);
write (fd, " I am Shatakshee Mishra\n", 24);
close (fd);
}
