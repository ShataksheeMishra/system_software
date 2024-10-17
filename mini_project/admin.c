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
bool admin_login(int clientSocket);
bool authenticate_admin(int clientSocket);
bool change_pass(int clientSocket);
void save_credentials(const char *username, const char *password);
bool verify_credentials(const char *username, const char *password);
struct Credentials
{
char username[50];
char password[10];
};
bool admin_login(int clientSocket)
{printf("hello\n");
send(clientSocket,"hello\n",strlen("hello\n"),0);

if(authenticate_admin(clientSocket))
{send(clientSocket,"login successful\n",strlen("login successful\n"),0);
ssize_t rbytes;
char rbuff[1024];
while(1)
{
char menu[]="select the option number \n1.Add new bank employee\n2.modify customer/employee details\n3.manage user roles\n4.change password\n5.logout\n6.exit";
send (clientSocket,menu,strlen(menu),0);
rbytes=recv(clientSocket,rbuff,sizeof(rbuff),0);
if(rbytes==-1)
{perror("error in reading choice");
return false;}
int choice=atoi(rbuff);
switch (choice){
	case 1:
		//if(add_employee(clientSocket))
	//{send(clientSocket,"successfuly added\n",strlen("successfully added\n"),0);}
	break;
	case 2:
	//	if(modify_customer(clientSocket))
	//{send(clientSocket,"successfully modify\n",strlen("successfully modify\n"),0);}
	break;
	case 3:
	//	if(manage_user(clientSocket))
	//{send(clientSocket,"success\n",strlen("success\n"),0);}
	break;
	case 4:
		if(change_pass(clientSocket))
	{send(clientSocket,"successfully changed\n",strlen("successfully changed\n"),0);}
	break;
	case 5:
		send(clientSocket,"successfully logged out\n",strlen("successfully logged out\n"),0);
		return true;
	break;
	case 6:
		close(clientSocket);
		break;
	 default:
                    send(clientSocket, "Invalid option. Please try again.\n", strlen("Invalid option. Please try again.\n"), 0);
                    break;
}//switch end
}//while end
}//authenticate end
}//admin login end
bool authenticate_admin(int clientSocket)
{
send(clientSocket,"hi\n",strlen("hi\n"),0);
printf("hi\n");
char username[50];
char password[10];
send(clientSocket,"enter username:\n",strlen("enter username:\n"),0);
ssize_t read=recv(clientSocket,username,sizeof(username),0);
if (read<=0)
{
close (clientSocket);
return 0;
}
if(username[read -1]=='\n')
{username[read -1]='\0';}
else
{username[read -1]='\0';}
send(clientSocket, "enter password:\n",strlen("enter password:\n"),0);
read=recv(clientSocket,password,sizeof(password),0);
if(read<=0)
{close(clientSocket);
return 0;
}
if(password[read -1]=='\n')
{
password[read -1]='\0';
}
else
{password[read -1]='\0';}
//if (strcmp(username,admin.username)==0 && strcmp(password,admin.password)==0)
   if (verify_credentials(username, password))
{return true;}
else
{send(clientSocket,"invalid credentials\n",strlen("invalid credentials\n"),0);
close(clientSocket);
return false;
}
}
bool change_pass(int clientSocket)
{
char new_pass[10];
send(clientSocket,"enter new password\n",strlen("enter new password\n"),0);
ssize_t rbytes=recv(clientSocket,new_pass,sizeof(new_pass),0);
if(rbytes<=0)
{send(clientSocket,"error in receiving password\n",strlen("error in receiving password\n"),0);
return false;}
if (new_pass[rbytes -1]=='\n')
{new_pass[rbytes -1]='\0';}
else
{new_pass[rbytes -1]='\0';}
save_credentials("Shatakshee",new_pass);
return true;
}

void save_credentials(const char *username, const char *password) {
FILE *file = fopen("adminlogin.txt", "w");
if (file == NULL) {
perror("Error opening file");
exit(EXIT_FAILURE);
}

    fprintf(file, "%s %s\n", username, password);
    fclose(file);
}
bool verify_credentials(const char *username, const char *password) {
    FILE *file = fopen("adminlogin.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return false;
    }

    char stored_username[50];
    char stored_password[10];

    while (fscanf(file, "%s %s", stored_username, stored_password) != EOF) {
        if (strcmp(stored_username, username) == 0 && strcmp(stored_password, password) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}
