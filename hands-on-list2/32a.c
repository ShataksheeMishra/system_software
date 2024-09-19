#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<fcntl.h>

int main(void)
{struct {int ticket_no;}db;

int fd, key,semid;
key=ftok(".",'a');
semid=(key,1,0);
struct sembuf buf={0,-1,0};
semid=semget(key,1,0);

fd=open("db",O_RDWR);
read(fd,&db,sizeof(db));
printf("before eterning cs\n");
semop(semid,&buf, 1);
printf("inside cs\n");
printf("current tickect no. - %d\n",db.ticket_no);
db.ticket_no ++;
lseek(fd,0L,SEEK_SET);
write(fd,&db,sizeof(db));
printf("ticket no. after updation - %d\n",db.ticket_no);
printf("press enter to exit cs\n");
getchar();
buf.sem_op=1;
semop(semid,&buf,1);
printf("exited cs\n");
}
