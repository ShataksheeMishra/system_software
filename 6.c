#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main (void)
{
char buffer[80];
read (0, buffer , sizeof(buffer));  
write (1,buffer, sizeof(buffer) );
}
