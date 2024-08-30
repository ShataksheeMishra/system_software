#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(){
if (!fork()){
	setsid();
	chdir("/");
	umask(0);
	while(1){
		sleep(5);
		printf("daemon is running");
}
}
else
exit(0);
}

