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
interval.tv_sec=5;
interval.tv_usec=0;
struct timeval value;
value.tv_sec=5;
value.tv_usec=0;
struct itimerval  initial;
initial.it_interval=interval;
initial.it_value=value;
int time= setitimer(ITIMER_PROF,&initial,NULL);
sleep(10);
while(1){}
} 
