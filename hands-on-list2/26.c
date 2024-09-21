/*
============================================================================
Name : 26.c
Author : Shatakshee Mishra
Description : Write a program to send messages to the message queue. Check $ipcs -q
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
int msgid=msgget(key,IPC_CREAT|0744);
my_msg.msg_type=1;
printf("Enter the message\n");
fgets(my_msg.msg_text,sizeof(my_msg.msg_text), stdin);
msgsnd(msgid,&my_msg,sizeof(my_msg.msg_text),0);
return 0;
}

/*output
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
Enter the message
hi
shatakshee@shatakshee:~/ss/hands-on-list2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01063545 0          shatakshee 744        0            0           
0x02063545 1          shatakshee 744        0            0           
0x03063545 2          shatakshee 744        100          2   
*/
