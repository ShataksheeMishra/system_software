 #include <sys/stat.h>
#include<stdio.h>
#include <unistd.h>

int main(){
char *path="fifofile";
if((mknod(path,0744,0)==-1))
{perror("error");}
printf("success");
}

