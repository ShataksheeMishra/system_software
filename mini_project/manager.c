#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include <fcntl.h>
#include <sys/file.h>
#include <sys/socket.h>
#include "admin.h"
#include "employee.h"
#include "customer.h"
bool man_login(int clientSocket);
bool authenticate_man(int clientSocket);
//bool add_customer(int cd);
//bool modify_customer(int clientSocket);
//bool change_password(int clientSocket);
bool man_login(int clientSocket)
{printf("hello\n");
send(clientSocket,"hello\n",strlen("hello\n"),0);

if(authenticate_man(clientSocket))

{send(clientSocket,"login successful\n",strlen("login successful\n"),0);
//ssize_t rbytes;
//char rbuff[1024];
while(1)
{
printf("i am in while\n");
fflush(stdout);
ssize_t rbytes;
char rbuff[1024];
char menu[]="select the option number \n1.Add new customer\n2.modify customer details\n3.approve reject loans\n4.view assigned loan\n5.change password\n6.logout\n7.exit\n";
send(clientSocket,menu,strlen(menu),0);
printf("bye");
rbytes=recv(clientSocket,rbuff,sizeof(rbuff),0);
if(rbytes==-1)
{perror("error in reading choice");
return false;}
int choice=atoi(rbuff);

/*switch (choice){
        case 1:
         if(add_customer(clientSocket))
        {
        send(clientSocket,"successfuly added\npress enter to continue\n",strlen("successfully added\npress enter to continue\n"),0);
        }
        break;
        case 2:
                if(modify_customer(clientSocket))
        {send(clientSocket,"successfully modify\n",strlen("successfully modify\n"),0);}
        break;
       case 3:
         //       if(manage_user(clientSocket))
        //{send(clientSocket,"success\n",strlen("success\n"),0);}
        break;
	case 4:
	break;
        case 5:
		printf("inside case 5\n");
                if(change_password(clientSocket))
        {send(clientSocket,"successfully changed\n",strlen("successfully changed\n"),0);}

        break;
        case 6:
                send(clientSocket,"successfully logged out\n",strlen("successfully logged out\n"),0);
                return true;
        break;
        case 7:
                close(clientSocket);
                break;
         default:
                    break;
}*/printf("out of switch\n");
fflush(stdout);
}//while end
}//authenticate end
}//admin login end
bool authenticate_man(int clientSocket)
{
send(clientSocket,"hi\n",strlen("hi\n"),0);
printf("hi\n");
char empid[50];
char password[10];
send(clientSocket,"empid:\n",strlen("empid:\n"),0);
ssize_t read1=recv(clientSocket,empid,sizeof(empid),0);
if (read1<=0)
{
close (clientSocket);
return 0;
}
if(empid[read1 -1]=='\n')
{empid[read1 -1]='\0';}
else
{empid[read1 -1]='\0';}
send(clientSocket, "enter password:\n",strlen("enter password:\n"),0);
read1=recv(clientSocket,password,sizeof(password),0);
if(read1<=0)
{close(clientSocket);
return 0;
}
if(password[read1 -1]=='\n')
{
password[read1 -1]='\0';
}
else
{password[read1 -1]='\0';}
//if (strcmp(username,admin.username)==0 && strcmp(password,admin.password)==0)
int db_fd = open("employee.txt", O_RDONLY);
    if (db_fd == -1) {
        perror("Error in opening the database file");
        return false;
    }

    char line[300];
    struct employee temp;
    //bool is_there = false;

    //struct flock lock;
    //memset(&lock, 0, sizeof(lock));
    //lock.l_type = F_WRLCK;  
    //lock.l_whence = SEEK_SET;  

    //off_t record_offset = 0;
    off_t current_position = 0;

    char buffer;
    int line_index = 0;

    while (read(db_fd, &buffer, 1) > 0) {
        if (buffer != '\n') {
            line[line_index++] = buffer;
        } else {
            line[line_index] = '\0';
            line_index = 0;

            current_position = lseek(db_fd, 0, SEEK_CUR);

            sscanf(line, "%[^,],%[^,],%[^,],%[^,]", temp.id, temp.password, temp.username, &temp.role);
            printf("Read Employee: ID=%s, Name=%s, Password=%s, Role=%s\n", temp.id, temp.password, temp.username, temp.role);
printf("%s,%s\n",temp.id,empid);

            if (atoi(temp.id)==atoi( empid)&& atoi(temp.password)==atoi(password)) {
                printf("Employee ID matched.\n");return true;}
   }//end of else
}//end of while

}//end of authenticate
