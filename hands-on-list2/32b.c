#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
int main(void){
int shmkey,shmid,semkey,semid;
char *data;
shmkey = ftok(".",'d');
shmid=shmget(shmkey,1024,IPC_CREAT|0744);
data =shmat(shmid,0,0);
semkey=ftok(".",'e');
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



/*ouput
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
critical section
enter text:hello
data from shared memory : hello
press enter to exit cs
exited cs
*/

