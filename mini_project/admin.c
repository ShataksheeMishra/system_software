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
bool admin_login(int clientSocket);
bool authenticate_admin(int clientSocket);
bool change_pass(int clientSocket);
void save_credentials(const char *username, const char *password);
bool verify_credentials(const char *username, const char *password);
bool add_employee(int clientSocket);
int get_id();
void update_id(int id);
int read_id();
bool modify_employee(int clientSocket);
bool manage_user(int clientSocket);
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
//ssize_t rbytes;
//char rbuff[1024];
while(1)
{
printf("i am in while\n");
fflush(stdout);
ssize_t rbytes;
char rbuff[1024];
char menu[]="select the option number \n1.Add new bank employee\n2.modify customer/employee details\n3.manage user roles\n4.change password\n5.logout\n6.exit";
send(clientSocket,menu,strlen(menu),0);
printf("bye");
rbytes=recv(clientSocket,rbuff,sizeof(rbuff),0);
if(rbytes==-1)
{perror("error in reading choice");
return false;}
int choice=atoi(rbuff);
switch (choice){
	case 1:
	 if(add_employee(clientSocket))
        {
        send(clientSocket,"successfuly added\npress enter to continue\n",strlen("successfully added\npress enter to continue\n"),0);
        }
	break;
	case 2:
		if(modify_employee(clientSocket))
	{send(clientSocket,"successfully modify\n",strlen("successfully modify\n"),0);}
	break;
	case 3:
		if(manage_user(clientSocket))
	{send(clientSocket,"success\n",strlen("success\n"),0);}
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
                    break;
}//switch end
printf("out of switch\n");
fflush(stdout);
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
bool add_employee(int clientSocket)
{
struct employee add;
add.id=get_id();
send(clientSocket,"enter username\n",strlen("enter username\n"),0);
int read=recv(clientSocket,add.username,sizeof(add.username),0);
if(read<=0)
{send(clientSocket,"error in fetching username\n",strlen("error in fetching username\n"),0);
return false;}
add.username[read-1]='\0';
send(clientSocket,"enter password\n",strlen("enter password\n"),0);
read=recv(clientSocket,add.password,sizeof(add.password),0);
if(read<=0)
{send(clientSocket,"error in fetching password\n",strlen("error in fetching password\n"),0);
return false;}
add.password[read-1]='\0';
send(clientSocket,"enter role of employee\n",strlen("enter role of employee\n"),0);
read=recv(clientSocket,add.role,sizeof(add.role),0);
if(read<=0)
{send(clientSocket,"error in fetching role\n",strlen("error in fetching role\n"),0);
return false;}
add.role[read-1]='\0';
FILE *file=fopen("employee.txt","a");
if(file!=NULL)
{fprintf(file,"%d,%s,%s,%s\n",add.id,add.password,add.username,add.role);
fclose(file);
printf("true\n");
fflush(stdout);
return true;}
perror("can not open employee file");
printf("false\n");
fflush(stdout);
return false;
}//end of add employee


int get_id()
{
int id=read_id();
update_id(id+1);
return id;}
int read_id()
{FILE *file=fopen("employee.txt","r");
int id=1;
if(file!=NULL)
{
fscanf(file,"%d",&id);
fclose(file);
}
return id;
}//end of read_id
void update_id(int id)
{
FILE *file=fopen("employee.txt","r+");
if (file==NULL)
{file=fopen("employee.txt","w");
if(file!=NULL){
fprintf(file,"%d\n",id);
fclose(file);
}
}
else{
fseek(file,0,SEEK_SET);
fprintf(file,"%d\n",id);
fclose(file);}
}//end update_id
/*
bool modify_employee(int clientSocket)
{
struct employee update;
char empid[10];
send (clientSocket,"enter employee id\n",strlen("enter employee id\n"),0);
int r=recv(clientSocket,empid,sizeof(empid),0);
if(r<=0)
{send(clientSocket,"error in fetching username\n",strlen("error in fetching username\n"),0);
return false;}
char *endptr;
int empid_int = strtol(empid, &endptr, 10);
//struct employee emp;
int fd=open("employee.txt",O_RDWR);
if (fd==-1)
{perror("error opening file");
return false;}
//if(fd==NULL){send(clientSocket,"no record\n",strlen("no record\n"),0);
//return false;}
else{
int tempid=read_id();
if(empid_int>=tempid)
{send(clientSocket,"please enter correct employee id\n",strlen("please enter correct employee id\n"),0);
return false;}
else{
update.id=empid_int;
struct flock lock;
lock.l_type=F_WRLCK;
lock.l_start=empid_int*sizeof(struct employee);
lock.l_len=sizeof(struct employee);
lock.l_whence=SEEK_SET;
lseek(fd,empid_int*sizeof(struct employee),SEEK_SET);
fcntl(fd,F_SETLKW,&lock);
if (read(fd, &update, sizeof(struct employee)) <= 0) {
        send(clientSocket, "Error in reading employee record\n", strlen("Error in reading employee record\n"), 0);
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        return false;
    }
send(clientSocket,"enter username\n",strlen("enter username\n"),0);
r=recv(clientSocket,update.username,sizeof(update.username),0);
if(r<=0)
{send(clientSocket,"error in fetching username\n",strlen("error in fetching username\n"),0);
return false;}
update.username[r-1]='\0';
send(clientSocket,"enter password\n",strlen("enter password\n"),0);
r=recv(clientSocket,update.password,sizeof(update.password),0);
if(r<=0)
{send(clientSocket,"error in fetching password\n",strlen("error in fetching password\n"),0);
return false;}
update.password[r-1]='\0';
send(clientSocket,"enter role\n",strlen("enter role\n"),0);
r=recv(clientSocket,update.role,sizeof(update.role),0);
if(r<=0)
{send(clientSocket,"error in fetching role\n",strlen("error in fetching role\n"),0);
return false;}
update.role[r-1]='\0';
lseek(fd,empid_int*sizeof(struct employee),SEEK_SET);
//char buffer[1024];
//int buffer_size=snprintf(buffer,sizeof(buffer),"%d,%s,%s,%s\n",update.id,update.password,update.username,update.role);
write(fd,&update,sizeof(struct employee));
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
return true;}
}//end of else
}//end of modify
*/
bool modify_employee(int clientSocket)
{
    struct employee update;
    char empid[10];
    
    // Prompt for employee ID
    send(clientSocket, "Enter employee ID\n", strlen("Enter employee ID\n"), 0);
    int r = recv(clientSocket, empid, sizeof(empid), 0);
    if (r <= 0) {
        send(clientSocket, "Error in fetching employee ID\n", strlen("Error in fetching employee ID\n"), 0);
        return false;
    }
    
    // Convert employee ID to integer
    char *endptr;
    int empid_int = strtol(empid, &endptr, 10);

    // Open the employee file
    int fd = open("employee.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return false;
    }
    
    // Check if the employee ID is valid
    int tempid = read_id();
    if (empid_int >= tempid) {
        send(clientSocket, "Please enter a correct employee ID\n", strlen("Please enter a correct employee ID\n"), 0);
        close(fd);
        return false;
    } 

    // Lock the specific record
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = empid_int * sizeof(struct employee);
    lock.l_len = sizeof(struct employee);
    lock.l_whence = SEEK_SET;
    
    // Move to the position of the employee record
    lseek(fd, empid_int * sizeof(struct employee), SEEK_SET);
    fcntl(fd, F_SETLKW, &lock);

    // Read the existing employee data
    if (read(fd, &update, sizeof(struct employee)) != sizeof(struct employee)) {
        send(clientSocket, "Error in reading employee record\n", strlen("Error in reading employee record\n"), 0);
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        return false;
    }

    // Update username
    send(clientSocket, "Enter new username\n", strlen("Enter new username\n"), 0);
    r = recv(clientSocket, update.username, sizeof(update.username), 0);
    if (r <= 0) {
        send(clientSocket, "Error in fetching username\n", strlen("Error in fetching username\n"), 0);
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        return false;
    }
    update.username[r - 1] = '\0';  // Null-terminate the string

    // Update password
    send(clientSocket, "Enter new password\n", strlen("Enter new password\n"), 0);
    r = recv(clientSocket, update.password, sizeof(update.password), 0);
    if (r <= 0) {
        send(clientSocket, "Error in fetching password\n", strlen("Error in fetching password\n"), 0);
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        return false;
    }
    update.password[r - 1] = '\0';  // Null-terminate the string

    // Update role
    send(clientSocket, "Enter new role\n", strlen("Enter new role\n"), 0);
    r = recv(clientSocket, update.role, sizeof(update.role), 0);
    if (read <= 0) {
        send(clientSocket, "Error in fetching role\n", strlen("Error in fetching role\n"), 0);
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        return false;
    }
    update.role[r - 1] = '\0';  // Null-terminate the string

    // Write the updated employee structure back to the file
    lseek(fd, empid_int * sizeof(struct employee), SEEK_SET);
    if (write(fd, &update, sizeof(struct employee)) != sizeof(struct employee)) {
        send(clientSocket, "Error in updating employee record\n", strlen("Error in updating employee record\n"), 0);
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        return false;
    }

    // Unlock the record
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);
    
    return true;
}


bool manage_user(int clientSocket)
{
struct employee update;
char empid[10];
send (clientSocket,"enter employee id\n",strlen("enter employee id\n"),0);
int read=recv(clientSocket,empid,sizeof(empid),0);
if(read<=0)
{send(clientSocket,"error in fetching username\n",strlen("error in fetching username\n"),0);
return false;}
char *endptr;
int empid_int = strtol(empid, &endptr, 10);
//struct employee emp;
int fd=open("employee.txt",O_RDWR);
if (fd==-1)
{perror("error opening file");
return false;}
//if(fd==NULL){send(clientSocket,"no record\n",strlen("no record\n"),0);
//return false;}
else{
int tempid=read_id();
if(empid_int>=tempid)
{send(clientSocket,"please enter correct employee id\n",strlen("please enter correct employee id\n"),0);
return false;}
else{

struct flock lock;
lock.l_type=F_WRLCK;
lock.l_start=empid_int*sizeof(struct employee);
lock.l_len=sizeof(struct employee);
lseek(fd,empid_int*sizeof(struct employee),SEEK_SET);
fcntl(fd,F_SETLKW,&lock);
send(clientSocket,"enter role\n",strlen("enter role\n"),0);
read=recv(clientSocket,update.role,sizeof(update.role),0);
if(read<=0)
{send(clientSocket,"error in fetching role\n",strlen("error in fetching role\n"),0);
return false;}
update.role[read-1]='\0';
lseek(fd, -1 * sizeof(struct employee), SEEK_CUR);
write(fd, &update, sizeof(struct employee));
lock.l_type = F_UNLCK;
fcntl(fd, F_SETLK, &lock);
close(fd);
return true;}
}
}//end of mange user
