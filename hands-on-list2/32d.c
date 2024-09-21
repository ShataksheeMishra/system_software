/*
============================================================================
Name : 32d.c
Author : Shatakshee Mishra
Description :Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 19th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>
union semun {
int val;
struct semid_ds *buff;
unsigned short int *array;
};

int main(void)
{union semun arg;
int key , semid;
key = ftok(".",'a');
semid=semget(key,1,0);
semctl(semid, 0, IPC_RMID);
printf("deleted ");}
