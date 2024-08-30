//Name -19
//Author- Shatakshee Mishra
//Roll no.- MT2024142
/*Write a program to find out time taken to execute getpid system call. Use time stamp counter.*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
unsigned long long rdtsc()
{	 unsigned long long dst;

	__asm__ __volatile__("rdtsc":"=A"(dst));
	return dst;
}
int main(void){
int i ,time;
unsigned long long int start,end;
start=rdtsc();
for(i=0;i<=100;i++)
	getpid();
end=rdtsc();
time=(end-start)/.23;
printf("function takes %d nano sec\n",time);
}

//output
/*
shatakshee@shatakshee:~/ss$ nano 19.c
shatakshee@shatakshee:~/ss$ cc 19.c
shatakshee@shatakshee:~/ss$ ./a.out
function takes 279547 nano sec
*/


