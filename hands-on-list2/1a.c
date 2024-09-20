/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Write a C, Ansi-style program to perform Record locking.
                       a. Implement write lock
Date: 12th Sep, 2024.
============================================================================
*/
#include<sys/time.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>
void handleSignal(int sig) {
    printf("Timer expired in 5 seconds and 5 microsecond interval and signal number is %d\n",sig);
}

int main(){
signal(SIGALRM, handleSignal);
struct timeval interval;
interval.tv_sec =5;
interval.tv_usec = 5;

struct timeval value;
value.tv_sec = 5;
value.tv_usec = 5;

struct itimerval newValue;
newValue.it_interval = interval;
newValue.it_value = value;

int timer = setitimer(ITIMER_REAL, &newValue, NULL);
sleep(10);
while (1) {}

}
