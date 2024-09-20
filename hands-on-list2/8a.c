#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int sig)
{
printf("caught SIGSEGV signal\n");
exit(1);

}



void main()
{
__sighandler_t stat;

stat= signal( SIGSEGV, (void*)handle_signal);

if( stat == SIG_ERR){
printf("error\n");
}

else{
raise(SIGSEGV);
}
}
