

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signalint_handler(int sig){
printf("received SIGINT but will not be called because of SIG_IGN\n");
}

int main()
{

signal(SIGINT,SIG_IGN);
printf("SIGINT is ignored\n");

//pressing cntrl+c has no effect here as signal is ignored

sleep(5);


signal(SIGINT,SIG_DFL);
printf("SIGINT is reset to it's default action\n");
//presssing ctrl+c here terminates the program which is the default action


sleep(5);

printf("program exited");
 
return 0;
}
