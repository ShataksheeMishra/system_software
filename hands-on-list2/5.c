#include<unistd.h>
#include<stdio.h>

int main(){

long sysConfig = sysconf(_SC_ARG_MAX);
printf("maximum length of arguments %ld\n",sysConfig);

}

/*output
shatakshee@shatakshee:~/ss/hands-on-list2$ cc 5.c
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
maximum length of arguments 2097152
*/
