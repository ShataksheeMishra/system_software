/*
============================================================================
Name : 10b.c
Author : Shatakshee Mishra
Description : 
Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void handler(int sig) {
    printf(" SIGINT");
	exit(0);
}

int main() {
struct sigaction sa;
memset(&sa, 0, sizeof(sa));
sa.sa_handler = handler;
sigaction(SIGINT, &sa, NULL);
while (1);

return 0;
}
