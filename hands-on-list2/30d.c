/*
============================================================================
Name : 30d.c
Author : Shatakshee Mishra
Description :Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 20th Sep, 2024.
============================================================================
*/
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
int main(void){
int key,shmid;
char *data;
key = ftok(".",'c');
shmid=shmget(key,1024,IPC_CREAT|0744);
data =shmat(shmid,0,0);
printf("shared memory attached\n");
printf("press enter to delete shared memory\n");
getchar();
shmctl(key, IPC_RMID, NULL);
printf("deleted shared memory\n");
}
