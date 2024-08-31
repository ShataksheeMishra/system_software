/*
============================================================================
Name : 15.c
Author : Shatakshee Mishra
Description : Write a program to display the environmental variable of the user (use environ).
Date: 22nd Aug, 2024.
============================================================================
*/
#include<stdio.h>
int main(void)
{extern char **environ;

int i=0;
while (environ[i]!=NULL)
printf("%s \n",environ[i++]);
return 0;

}
