#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<pthread.h>
#include<stdbool.h>
#include<string.h>
#define PORT 5050
void *handleclient(void * arg)
{
int clientSocket= *((int *)arg);
char buff[1024];
char menu[]="select number corresponding to your role:\n1.customer\n2.bank employee\n3.manager\n4.admin\n";
 send(clientSocket, menu, strlen(menu),0);
 while (1) {
        int bytesRead = recv(clientSocket, buff, sizeof(buff), 0);
        if (bytesRead <= 0) 
          {
            close(clientSocket);
            pthread_exit(NULL);
          }
}}
int main()
{
int serverSocket,clientSocket;
struct sockaddr_in serverAddr,clientAddr;
socklen_t clientAddrLen = sizeof(clientAddr);

serverSocket=socket(AF_INET,SOCK_STREAM,0);
if(serverSocket==-1)
{
	perror("creation failed");
	exit(1);
}
serverAddr.sin_family=AF_INET;
serverAddr.sin_port=htons(PORT);
serverAddr.sin_addr.s_addr=INADDR_ANY;
if(bind(serverSocket,(struct sockaddr *)&serverAddr,sizeof(serverAddr))==-1)
{	perror("binding failed");
	exit(1);
}
if(listen(serverSocket,5)==-1)
{
	perror("listening failed");
	exit(1);
}
while(1)
{
clientSocket=accept(serverSocket,(struct sockaddr *)&clientAddr,&clientAddrLen);
if(clientSocket==-1)
{
	perror("connection failed");
	continue;
}
pthread_t client_thread;
pthread_create(&client_thread,NULL,handleclient,(void *)&clientSocket);
}
close(serverSocket);
return 0;
}

