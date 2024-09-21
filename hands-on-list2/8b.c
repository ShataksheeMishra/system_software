/*
============================================================================
Name : 8b.c
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
