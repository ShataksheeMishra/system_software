/*
============================================================================
Name : 2.c
Author : Shatakshee Mishra
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 12th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>
#include<stdint.h>
#include<time.h>
int main()
{struct rlimit limit;
int a=getrlimit(RLIMIT_CPU,&limit);
printf("limits:\n soft:%jd\n hard:%jd\n",(intmax_t) limit.rlim_cur,(intmax_t) limit.rlim_max);
}
