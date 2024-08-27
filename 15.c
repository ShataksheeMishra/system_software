/*Write a program to display the environmental variable of the user (use environ).*/
#include<stdio.h>
int main(void)
{extern char **environ;

int i=0;
while (environ[i]!=NULL)
printf("%s \n",environ[i++]);
return 0;

}
