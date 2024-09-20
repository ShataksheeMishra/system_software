#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void  handle_signal()
{
printf("caught SIGFPE signal\n");
exit(0);
}

void main()
{

__sighandler_t stat;
stat = signal(SIGFPE , (void*)handle_signal);

raise(SIGFPE);

}
