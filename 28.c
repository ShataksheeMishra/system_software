/*
============================================================================
Name : 28.c
Author : Shatakshee Mishra
Description : Write a program to get maximum and minimum real time priority.
Date: 30th Aug, 2024.
============================================================================
*/
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

