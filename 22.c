
/*Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){
int fd;
fd=open("fork",O_RDWR);
if(!fork())
	write(fd,"written by child process\n",25);
else
	write(fd,"written by parent process\n",26);
close (fd);}

//output
/*
./a.out
shatakshee@shatakshee:~/ss$ cat fork
written by parent process
written by child process
*/
