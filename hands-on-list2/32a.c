/*
============================================================================
Name : 32a.c
Author : Shatakshee Mishra
Description :Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 19th Sep, 2024.
============================================================================
*/#include<stdio.h>
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

/*output
shatakshee@shatakshee:~/ss/hands-on-list2$ cc 32a.c
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
before eterning cs
inside cs
current tickect no. - 20
ticket no. after updation - 21
press enter to exit cs

exited cs
output of another terminal
cc 32a.c
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
before eterning cs
*/

