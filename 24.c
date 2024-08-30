
/*. Write a program to create an orphan process.*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
int main()
{printf("i am parent process\n");
printf("my pid :%d\n",getpid());
if(!fork()){
	printf("i am child process\n ");
	sleep(5);
	printf(" pid of my parent: %d\n",getppid());
}
}

// output
/*
shatakshee@shatakshee:~/ss$ ./a.out
i am parent process
my pid :9703
i am child process
shatakshee@shatakshee:~/ss$   pid of my parent: 1504
*/
