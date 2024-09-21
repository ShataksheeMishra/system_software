/*
============================================================================
Name : 1c.c
Author : Shatakshee Mishra
Description : Write a C, Ansi-style program to perform Record locking.
                       a. Implement write lock
Date: 12th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<signal.h>
void signalhandle(int sig)
{printf("time expired in 5 sec and 0 msec signal is %d\n",sig);
}
int main(){
signal(SIGPROF, signalhandle);
struct  timeval interval;
interval.tv_sec=10;
interval.tv_usec=10;
struct timeval value;
value.tv_sec=10;
value.tv_usec=10;
struct itimerval  initial;
initial.it_interval=interval;
initial.it_value=value;
int time= setitimer(ITIMER_PROF,&initial,NULL);
sleep(10);
while(1){}
} 
