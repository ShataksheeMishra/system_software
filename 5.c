/*Write a program to create five new files with infinite loop. Execute the program
 in the background and check the file descriptor table at /proc/pid/fd.*/
#include<stdio.h>
#include<fcntl.h>
int main(void)
{int fd1,fd2,fd3,fd4,fd5;
fd1=open("f1", O_CREAT|O_RDWR,0764);
fd2=open("f2", O_CREAT|O_RDWR,0764);
fd3=open("f3", O_CREAT|O_RDWR,0764);
fd4=open("f4", O_CREAT|O_RDWR,0764);
fd5=open("f5", O_CREAT|O_RDWR,0764);
for (;;);
}



