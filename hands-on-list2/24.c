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
