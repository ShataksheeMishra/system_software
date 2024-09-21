/*
============================================================================
Name : 10a.c
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
    printf(" Segmentation Fault\n");
    exit(1);
}

int main() {
    
struct sigaction sa;
memset(&sa, 0, sizeof(sa));
sa.sa_handler = handler;
sigaction(SIGSEGV, &sa, NULL);
int *ptr = NULL;
*ptr = 42;
return 0;

}
