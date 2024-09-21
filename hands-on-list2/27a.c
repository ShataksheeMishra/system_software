/*
============================================================================
Name : 27a.c
Author : Shatakshee Mishra
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 21st Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
struct mg_info{
long msg_type;
char msg_text[50];
}my_msg;
int main(){
int key=ftok(".",3);
int msg_id=msgget(key,IPC_CREAT|0744);
 msgrcv(msg_id,&my_msg,sizeof(my_msg.msg_text),1,0);
printf("received message is: %s\n",my_msg.msg_text); 
return 0;
}
