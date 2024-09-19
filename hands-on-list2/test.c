#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/types.h>
#include<sys/ipc.h>
int main(void)
{
int key,semid;
key =ftok(".",a);
semid=(key,1,
