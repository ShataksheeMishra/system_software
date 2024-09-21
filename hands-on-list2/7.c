#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *myThread(void *arg)
{int num = *((int*)arg);
pthread_t thread_id = pthread_self();
printf("hi i am thread %lu\n",thread_id);
return NULL;
}
int main()
{pthread_t thread[3];
int arg[3];

for(int i=0;i<3;i++)
{
arg[i] = i+1;
pthread_create(&thread[i],NULL,myThread, &arg[i]);
}

for(int i=0;i<3;i++)
{
pthread_join(thread[i] , NULL);
}
}

/*output
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
hi i am thread 140722222001956
hi i am thread 140722222001960
hi i am thread 140722222001964
*/
