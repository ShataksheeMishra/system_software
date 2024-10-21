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
//struct Credentials
//{
//char username[50];
//char password[10];
//};
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
//int empid=get_id();
//add.id=empid;
send(clientSocket,"enter empid\n",strlen("enter empid\n"),0);
int read=recv(clientSocket,add.id,sizeof(add.id),0);
add.id[read -1]='\0';
send(clientSocket,"enter username\n",strlen("enter username\n"),0);
 read=recv(clientSocket,add.username,sizeof(add.username),0);
//add.id[read -1]='\0';
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
{fprintf(file,"%s,%s,%s,%s\n",add.id,add.password,add.username,add.role);
fclose(file);
printf("true\n");
fflush(stdout);
return true;}
perror("can not open employee file");
printf("false\n");
fflush(stdout);
return false;
}//end of add employee


/*int get_id()
{FILE *file = fopen("employee.txt", "r");
    if (file == NULL) {
        perror("Error opening employee file");
        return 1; 
    }

    int max_id = 0;
    char line[1024];
    
    while (fgets(line, sizeof(line), file)) {
        int id;
        sscanf(line, "%d", &id);
        if (id > max_id) {
            max_id = id;
        }
    }

    fclose(file);
    return max_id + 1; 
}
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
*/
bool modify_employee(int cd) {
    struct employee data_new;
    char empid[10];
    char format[300];
    char enter_id[] = "Enter employee id:";

    write(cd, enter_id, sizeof(enter_id));
    ssize_t bytes_id = read(cd, empid, sizeof(empid));
    if (bytes_id == -1) {
        perror("Error in receiving Employee ID");
        return false;
    }
    printf("Received Employee ID: %s\n", empid);

    write(cd, "username:", strlen("username:"));
   ssize_t read1=  read(cd, data_new.username, sizeof(data_new.username));
if(read1<=0)
{
                close(cd);exit(1);}
                if(data_new.username[read1 -1]=='\n')
                        data_new.username[read1 -1]='\0';
                else
                        data_new.username[read1]='\0';


    write(cd, "id:", strlen("id:"));
    read(cd, data_new.id, sizeof(data_new.id));
	write(cd,"role",strlen("role"));
	ssize_t data_read=read(cd,data_new.role,sizeof(data_new.role));
if (data_read <= 0)
                {
                        close(cd);
                        exit(1);
                }

                if(data_new.id[data_read-1]=='\n')
                        data_new.id[data_read-1]='\0';
                else    
                        data_new.id[data_read]='\0';


    int db_fd = open("employee.txt", O_RDWR);
    if (db_fd == -1) {
        perror("Error in opening the database file");
        return false;
    }

    char line[300];
    struct employee temp;
    bool is_there = false;

    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK;  
    lock.l_whence = SEEK_SET;  

    off_t record_offset = 0;
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
            if (atoi(temp.id)==atoi( empid)) {
                printf("Employee ID matched.\n");
                lock.l_start = current_position - strlen(line) - 1;
                lock.l_len = strlen(line) + 1;

                if (fcntl(db_fd, F_SETLK, &lock) == -1) {
                    perror("Error in obtaining lock");
                    close(db_fd);
                    return false;
                }

                strcpy(data_new.password, temp.password);  
                snprintf(format, sizeof(format), "%s,%s,%s,%s\n", data_new.id, data_new.password, data_new.username, data_new.role);

                lseek(db_fd, current_position - strlen(line) - 1, SEEK_SET);

                if (write(db_fd, format, strlen(format)) == -1) {
                    write(cd, "Error in Updating Data", strlen("Error in Updating Data"));
                    close(db_fd);
                    return false;
                }

                lock.l_type = F_UNLCK;
                if (fcntl(db_fd, F_SETLK, &lock) == -1) {
                    perror("Error in releasing the lock");
                    close(db_fd);
                    return false;
                }

                is_there = true;
                break;
            }
        }
    }

    close(db_fd);

    if (!is_there) {
        write(cd, "Employee Not Found", strlen("Employee Not Found"));
        return false;
    }

    return true;
}


bool manage_user(int cd)
{
struct employee data_new;
    char empid[10];
    char format[300];
    char enter_id[] = "enter employee id:";

    write(cd, enter_id, sizeof(enter_id));
    ssize_t bytes_id = read(cd, empid, sizeof(empid));
    if (bytes_id == -1) {
        perror("error in receiving employee id");
        return false;
    }
    empid[bytes_id] = '\0';
    printf("Received employee id: %s\n", empid);

    //write(cd, "Name:", strlen("Name:"));
    //read(cd, data_new.username, sizeof(data_new.username));

    //write(cd, "ID:", strlen("ID:"));
    //read(cd, data_new.id, sizeof(data_new.id));
	write(cd,"role",strlen("role"));
	read(cd,data_new.role,sizeof(data_new.role));

    int db_fd = open("employee.txt", O_RDWR);
    if (db_fd == -1) {
        perror("Error in opening the database file");
        return false;
    }

    char line[300];
    struct employee temp;
    bool is_there = false;

    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK; 
    lock.l_whence = SEEK_SET;  

    off_t record_offset = 0;
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
            printf("Read Employee: ID=%s, Password=%s, Username=%s, Role=%s\n", temp.id, temp.password, temp.username, temp.role);
	printf("%s,%s\n",temp.id,empid);
            if (atoi(temp.id)==atoi( empid)) {
                printf("Employee ID matched.\n");

                lock.l_start = current_position - strlen(line) - 1; 
                lock.l_len = strlen(line) + 1; 

                if (fcntl(db_fd, F_SETLK, &lock) == -1) {
                    perror("Error in obtaining lock");
                    close(db_fd);
                    return false;
                }

                strcpy(data_new.password, temp.password); 
                snprintf(format, sizeof(format), "%s,%s,%s,%s\n", temp.id, temp.password, temp.username, data_new.role);

                lseek(db_fd, current_position - strlen(line) - 1, SEEK_SET);

                if (write(db_fd, format, strlen(format)) == -1) {
                    write(cd, "Error in Updating Data", strlen("Error in Updating Data"));
                    close(db_fd);
                    return false;
                }

                lock.l_type = F_UNLCK;
                if (fcntl(db_fd, F_SETLK, &lock) == -1) {
                    perror("Error in releasing the lock");
                    close(db_fd);
                    return false;
                }

                is_there = true;
                break;
}
}
}

    close(db_fd);

    if (!is_there) {
        write(cd, "Employee Not Found", strlen("Employee Not Found"));
        return false;
    }

    return true;
}

