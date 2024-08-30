
/*Write a program to create a Zombie state of the running program.*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
if (!fork()){
printf("inside child\n");
printf("parent pid:%d \n",getppid());
}
else
sleep(10);
}





