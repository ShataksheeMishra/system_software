/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/
/*Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(void)
{ struct {int ticket_no;}db;
struct flock lock;
int fd;
lock.l_type=F_WRLCK;
lock.l_start=0;
lock.l_whence=SEEK_SET;
lock.l_pid=getpid();
lock.l_len=0;
fd=open("db",O_RDWR);
read(fd,&db,sizeof(db));
printf("before eterning cs\n");
fcntl(fd,F_SETLKW,&lock);
printf("inside cs\n");
printf("current tickect no. - %d\n",db.ticket_no);
db.ticket_no ++;
lseek(fd,0L,SEEK_SET);
write(fd,&db,sizeof(db));
printf("ticket no. after updation - %d\n",db.ticket_no);
printf("press enter to exit cs\n");
getchar();
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("exited cs\n");
}
