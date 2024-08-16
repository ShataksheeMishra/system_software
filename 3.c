#include <fcntl.h>
#include <stdio.h>
int main (void){
printf ("fd =%d\n" , creat("myfile",0744));
}
