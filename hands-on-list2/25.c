/*
============================================================================
Name : 25.c
Author : Shatakshee Mishra
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include<time.h>

int main(){
struct msqid_ds msginfo;
int  key=ftok(".",2);
int msgid=msgget(key,IPC_CREAT|0744);
msgctl(msgid,IPC_STAT,&msginfo);
printf("Access Permission: %o\n", msginfo.msg_perm.mode);
printf("UID: %d, GID: %d\n", msginfo.msg_perm.uid, msginfo.msg_perm.gid); 
printf("Time of last message sent: %s", ctime(&msginfo.msg_stime));
printf("Time of last message received: %s", ctime(&msginfo.msg_rtime));
printf("Time of last change: %s", ctime(&msginfo.msg_ctime));
printf("Size of the queue: %ld bytes\n", msginfo.__msg_cbytes);
printf("Number of messages : %ld\n", msginfo.msg_qnum); 
printf("Maximum number of bytes allowed: %ld\n", msginfo.msg_qbytes);
printf("PID of last msgsnd: %d\n", msginfo.msg_lspid);
printf("PID of last msgrcv: %d\n", msginfo.msg_lrpid);
return 0;

}
