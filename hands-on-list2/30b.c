#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
int main(void){
int key,shmid;
char *data;
key = ftok(".",'c');
shmid=shmget(key,1024,IPC_CREAT|0744);
data =shmat(shmid,0,SHM_RDONLY);
printf("enter text:");
scanf("%[^\n]",data);
printf("data from shared memory : %s\n", data);
}

/*output
cc 30b.c
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
enter text:hi 
Segmentation fault (core dumped)
*/
