0#include<stdio.h>
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
serv.sin_port = htons (5055);

bind (sd, (void*)(&serv), sizeof (serv));
listen (sd, 5);
sz=sizeof(cli);
nsd = accept (sd,(void*)( &cli), &sz);
read(nsd,buff,sizeof (buff));
printf("message from client:%s\n",buff);
write(nsd,"hi i am server\n",16);
}



/*output 
cc 33_server.c -o server
shatakshee@shatakshee:~/ss/hands-on-list2$ ./server
message from client:hi i am client
*/
