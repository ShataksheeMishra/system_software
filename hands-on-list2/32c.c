/*
============================================================================
Name : 32c.c
Author : Shatakshee Mishra
Description : Write a C, Ansi-style program to perform Record locking.
                       a. Implement write lock
Date: 20th Sep, 2024.
============================================================================
*/
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
int main(void){
int shmkey,shmid,semkey,semid;
char *data;
shmkey = ftok(".",'g');
shmid=shmget(shmkey,1024,IPC_CREAT|0744);
data =shmat(shmid,0,0);
semkey=ftok(".",'f');
semid=(semkey,1,0);
struct sembuf buf={0,-1,0};
semid=semget(semkey,1,0);
semop(semid,&buf, 1);
printf("critical section\n");
printf("enter text:");
scanf("%[^\n]",data);
printf("data from shared memory : %s\n", data);

printf("press enter to exit cs\n");
getchar();
buf.sem_op=1;
semop(semid,&buf,1);
printf("exited cs\n");
}


/*output
hatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
critical section
enter text:bye
data from shared memory : bye
press enter to exit cs
exited cs
shatakshee@shatakshee:~/ss/hands-on-list2$ 

shatakshee@shatakshee:~/ss/hands-on-list2$ cc 32c.c
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
critical section
enter text:hi
data from shared memory : hi
press enter to exit cs
exited cs
*/
