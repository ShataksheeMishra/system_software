/*Write a program to copy file1 into file2 ($cp file1 file2).*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main (int argc, char *argf[])
{
if (argc != 3)
{printf("error");
return 0;
}
int fd_read=open(argf[1], O_RDONLY);
int fd_write=open(argf[2], O_RDWR | O_CREAT | O_EXCL, 0744);
while (1)
{char buff;
int r=read(fd_read,&buff,sizeof buff);
if (r==0)
break;
int w=write(fd_write,&buff,sizeof buff);
}
}
