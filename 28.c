/*
============================================================================
Name : 1a.c
Author : Shatakshee Mishra
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/
/*Write a program to get maximum and minimum real time priority.*/
#include<stdio.h>
#include<sched.h>
int main(){
printf("round robin -\n");
printf("min priority : %d  max priority : %d\n",sched_get_priority_min(SCHED_RR),sched_get_priority_max(SCHED_RR));
printf("FIFO -\n");
printf("min priority : %d  max priority : %d\n",sched_get_priority_min(SCHED_FIFO),sched_get_priority_max(SCHED_FIFO));
printf("other -\n");
printf("min priority : %d  max priority : %d\n",sched_get_priority_min(SCHED_OTHER),sched_get_priority_max(SCHED_OTHER));
}

