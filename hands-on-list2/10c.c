/*
============================================================================
Name : 10c.c
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
    printf(" Floating Point Exception\n");
    exit(1);
}

int main() {
struct sigaction sa;
memset(&sa, 0, sizeof(sa));
sa.sa_handler = handler;
sigaction(SIGFPE, &sa, NULL);
int x = 10;
int y = 0;
int z = x / y;
return 0;
}
