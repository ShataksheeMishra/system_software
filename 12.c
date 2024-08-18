/*Write a program to find out the opening mode of a file. Use fcntl.*/
#include <stdio.h>
#include<fcntl.h>
#include <unistd.h>
int main (void)
{int fd,mode;
 
fd = open("foods",O_RDWR);
mode= fcntl(fd, F_GETFL);
printf("mode = %d - ",mode);
switch(mode){
	case 32768: printf("read only mode"); break;
	case 32769: printf("write only mode");break;
	case 32770: printf("read and write mode");break;
}

}
