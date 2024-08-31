/*
============================================================================
Name : 30.c
Author : Shatakshee Mishra
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 30th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(){
if (!fork()){
	setsid();
	chdir("/");
	umask(0);
	while(1){
		sleep(2);
		printf("daemon is running\n");
}
}
else
exit(0);
}

