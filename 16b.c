/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/file.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
int main(void)
{struct flock lock;
int w,fd,rd,wr;
char buff[1024];
fd=open("file1",O_RDWR);
lock.l_type=F_RDLCK;
lock.l_whence=SEEK_SET;
lock.l_len=0;
lock.l_pid=getpid();
lock.l_start=0;
printf("before entering cs\n");
fcntl(fd,F_SETLKW,&lock);
printf("inside cs\n");
while(read (fd,buff,1))
{
        if(buff[0]=='\n')
        getchar();
        else 
         w= write(0,buff,1);



}

//rd=read(fd,buff,1);
//wr=write(0,buff,1);
printf("press enter to exit  cs\n");
getchar();
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("exit cs\n");
}
