

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void handle_signal() 
{
printf("caught SIGINT signal\n" );
exit(0);
}


void  main()
{

__sighandler_t stat;

stat =  signal(SIGINT , (void*)handle_signal);
raise(SIGINT);


}
