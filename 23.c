/*
============================================================================
Name : 23.c
Author : Shatakshee Mishra
Description : Write a program to create a Zombie state of the running program.
Date: 30th Aug, 2024.
============================================================================
*/

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





