#include <netinet/in.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void handle_client(void *nsd,void *sd) {
    char buff[80];
close(sd);
read(nsd,buff,sizeof (buff));
printf("message from client:%s\n",buff);
write(nsd,"hi i am server\n",16);
}

int main(){
int sd,nsd,sz;
struct sockaddr_in serv, cli;
char buff[80];
sd = socket (AF_UNIX, SOCK_STREAM, 0);

serv.sin_family = AF_UNIX;
serv.sin_addr.s_addr = INADDR_ANY;
serv.sin_port = htons (8080);

bind (sd, (void*)(&serv), sizeof (serv));
listen (sd, 5);
printf("server is listening \n");
sz=sizeof(cli);
while(1){
nsd = accept (sd,(void*)( &cli), &sz);


pthread_t threadID;
   (pthread_create(&threadID, NULL, (void *)handle_client, (&nsd,&sd)));
}
close(nsd);
}
