#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
unsigned long long rdtsc()
{        unsigned long long dst;

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

