
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void handle_sigvtalrm()
{
    printf("SIGVTALRM caught\n");
    exit(0);
}

void main()
{
    __sighandler_t status;
struct itimerval timer;
timer.it_interval.tv_sec = 0;
timer.it_interval.tv_usec = 0;
timer.it_value.tv_sec = 5;
timer.it_value.tv_usec = 0;
int timerStatus = setitimer(ITIMER_VIRTUAL, &timer, 0);
status = signal(SIGVTALRM, (void *)handle_sigvtalrm);
 while (1)
{}
}