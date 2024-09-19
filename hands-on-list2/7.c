#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *myThread(void *vargp)
{printf("hi i am thread %d\n",vargp);
sleep(5);
return NULL;
}
int main()
{
pthread_t tid;
pthread_create(&tid,NULL,myThread,NULL);
pthread_create(&tid,NULL,myThread,NULL);
pthread_create(&tid,NULL,myThread,NULL);
pthread_create(&tid,NULL,myThread,NULL);
getchar();
pthread_join(tid,NULL);
}
