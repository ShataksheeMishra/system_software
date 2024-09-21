/*
============================================================================
Name : 8a.c
Author : Shatakshee Mishra
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 20th Sep, 2024.
============================================================================
*/

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
