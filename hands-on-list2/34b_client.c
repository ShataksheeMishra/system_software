#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{struct sockaddr_in serv;
int sd;
char buff[80];
sd = socket (AF_UNIX, SOCK_STREAM, 0);

serv.sin_family = AF_UNIX;
serv.sin_addr.s_addr = INADDR_ANY;
serv.sin_port = htons (5081);
connect (sd,(void*)( &serv),sizeof (serv));
write(sd,"hi i am client\n",16);
read(sd,buff,sizeof (buff));
printf("message from server %s\n",buff);
}
