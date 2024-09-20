#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* func(void* arg) {
int num = *((int*)arg);
printf("Thread no. %d\n", num);
pthread_exit(NULL);
}

int main() {
pthread_t thread[3];
int arg[3];  
int i;
for (i = 0; i < 3; i++) {
        arg[i] = i+1 ;
        pthread_create(&thread[i], NULL, func, &arg[i]);  
    }

   
    for (i = 0; i < 3; i++) {
        pthread_join(thread[i], NULL);
    }

    printf(" execution of all threads finished\n");

    return 0;
}

/*output
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
Thread no. 1
Thread no. 2
Thread no. 3
 execution of all threads finished
*/
