#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main(){
struct msqid_ds msginfo;
int key=ftok(".",4);
int msg_id=msgget(key,IPC_CREAT|0744);
msgctl(msg_id,IPC_STAT,&msginfo);
printf("The current permissions: %o\n",msginfo.msg_perm.mode);
msginfo.msg_perm.mode=0766;
msgctl(msg_id,IPC_SET,&msginfo);
printf("The New permissions: %o\n",msginfo.msg_perm.mode);

}
