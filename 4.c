#include <stdio.h>
#include <fcntl.h>
int main (void){ 
int fd,fd1;
fd =  open("foods" , O_RDWR);
fd1 =open("foods" , O_RDWR|O_EXCL|O_CREAT,0744); 
printf("fd= %d,%d\n",fd,fd1);
}
