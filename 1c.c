#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main (void){
int fd;
char buff[80];
fd=open("myfifo", O_WRONLY);
printf("enter name:");
scanf("%[^\n]",buff);
write(fd,buff,sizeof(buff));
}
