/*
============================================================================
Name : 34a_server.c
Author : Shatakshee Mishra
Description :Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 19th Sep, 2024.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/types.h>
int main(){
int sd,nsd,sz;
struct sockaddr_in serv, cli;
char buff[80];
sd = socket (AF_UNIX, SOCK_STREAM, 0);

serv.sin_family = AF_UNIX;
serv.sin_addr.s_addr = INADDR_ANY;
serv.sin_port = htons (5080);

bind (sd, (void*)(&serv), sizeof (serv));
listen (sd, 5);
sz=sizeof(cli);
while(1){
nsd = accept (sd,(void*)( &cli), &sz);
if(!(fork())){
close(sd);
read(nsd,buff,sizeof (buff));
printf("message from client:%s\n",buff);
write(nsd,"hi i am server\n",16);
exit(0);
}
else 
close(nsd);
}
}

/*output
cc 34a_server.c
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
message from client:hi i am client

#message from another client

message from client:hi i am client

*/
