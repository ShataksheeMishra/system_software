#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main(){
int key=ftok(".",5);
int msgid=msgget(key,IPC_CREAT|0744);
msgctl(msgid,IPC_RMID,NULL);
printf("Queue is removed\n");
return 0;
}
