
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handleSigstop(int signum) {
    printf(" catch SIGSTOP\n");
}

int main() {
signal(SIGSTOP, handleSigstop) ;
printf("Process %d is running\n", getpid());
while (1) {
printf("Running %d\n",getpid());
sleep(3);
}
return 0;
}
