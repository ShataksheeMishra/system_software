/*Write a program to take input from STDIN and display on STDOUT.
 Use only read/write system calls. */
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main (void)
{
char buffer[80];
read (0, buffer , sizeof(buffer));  
write (1,buffer, sizeof(buffer) );
}
