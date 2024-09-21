/*
============================================================================
Name : 1b.c
Author : Shatakshee Mishra
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
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
signal(SIGVTALRM, handleSignal);
struct timeval interval;
interval.tv_sec =10;
interval.tv_usec = 10;

struct timeval value;
value.tv_sec = 10;
value.tv_usec = 10;

struct itimerval newValue;
newValue.it_interval = interval;
newValue.it_value = value;

int timer = setitimer(ITIMER_VIRTUAL, &newValue, NULL);
sleep(10);
while (1) {}

}
