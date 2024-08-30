#include<stdio.h>
#include<unistd.h>
int main(void)
{
execle("/bin/ls","ls","-rl",NULL);
} 
