/*
============================================================================
Name : 13a.c
Author : Shatakshee Mishra
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 21st Sep, 2024.
============================================================================
*/

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
