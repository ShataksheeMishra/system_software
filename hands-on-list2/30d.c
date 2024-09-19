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
