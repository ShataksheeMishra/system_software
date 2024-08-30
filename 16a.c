/*16. Write a program to perform mandatory locking.
a.implement write lock.*/
#include<stdio.h>
#include<sys/file.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
struct  flock lock;
int fd,wr,rd;
char buff[80];
 fd= open("foods",O_RDWR);
lock.l_type=F_WRLCK;
lock.l_whence=SEEK_SET;
lock.l_start=0;
lock.l_len=0;
lock.l_pid=getpid();
printf("before entering cs\n");
//printf("inside cs\n");

fcntl(fd,F_SETLKW,&lock);
printf("inside cs\n");
rd=read(0,buff,sizeof(buff));
lseek(fd,1L,SEEK_END);
wr=write(fd,buff,sizeof(buff));
printf("press enter to exit cs\n");
getchar();
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("exited cs\n");

}


