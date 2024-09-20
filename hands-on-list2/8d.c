#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_alrm()
{
printf("caught signal alarm\n");
}

void main()
{

__sighandler_t stat;
stat = signal(SIGALRM , (void*)sig_alrm);
raise(SIGALRM);
}
