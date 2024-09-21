/*
============================================================================
Name : 8d.c
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
