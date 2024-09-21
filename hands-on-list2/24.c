/*
============================================================================
Name : 24.c
Author : Shatakshee Mishra
Description : Write a program to create a message queue and print the key and message queue id.
Date: 21st Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main(){
int key=ftok(".",1);
int msgid=msgget(key,IPC_CREAT|0744);
printf("Key:%d\n",key);
printf("Message Queue id:%d\n",msgid);
return 0;

}
