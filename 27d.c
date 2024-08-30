#include<stdio.h>
#include<unistd.h>
int main(void)
{char *path ="/bin/ls";
char *argv[]={path,"-Rl",NULL};
execv(path,argv);
} 
