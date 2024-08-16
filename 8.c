#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int  main (void)
{int fd ;
char buff;
fd = open("foods",O_RDWR);
read (fd, buff, sizeof(buff));
close (fd);
}
