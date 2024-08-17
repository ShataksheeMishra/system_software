/*Write a program to create a file and print the file descriptor value.
 Use creat ( ) system call*/
#include <fcntl.h>
#include <stdio.h>
int main (void){
printf ("fd =%d\n" , creat("myfile",0744));
}
