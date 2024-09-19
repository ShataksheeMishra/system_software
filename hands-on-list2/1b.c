
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
interval.tv_sec =5;
interval.tv_usec = 5;

struct timeval value;
value.tv_sec = 5;
value.tv_usec = 5;

struct itimerval newValue;
newValue.it_interval = interval;
newValue.it_value = value;

int timer = setitimer(ITIMER_VIRTUAL, &newValue, NULL);
sleep(10);
while (1) {}

}
