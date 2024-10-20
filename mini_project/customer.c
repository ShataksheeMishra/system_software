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
#include "transaction.h"
bool customer_login(int clientSocket);
bool authenticate_customer(int clientSocket);
bool account_bal(int clientSocket);
bool deposit(int clientSocket);
void update_bal(int amount);
bool customer_login(int clientSocket)
{printf("hello\n");
send(clientSocket,"hello\n",strlen("hello\n"),0);

if(authenticate_customer(clientSocket))

{send(clientSocket,"login successful\n",strlen("login successful\n"),0);
//ssize_t rbytes;
//char rbuff[1024];
while(1)
{
printf("i am in while\n");
fflush(stdout);
ssize_t rbytes;
char rbuff[1024];
char menu[]="select the option number \n1.view account balance\n2.deposit money\n3.withdraw money\n4.transfer funds\n5.apply loan\n6.change password\n7.adding feedback\n8.view transaction history\n9.logout\n10.exit\n";
send(clientSocket,menu,strlen(menu),0);
printf("bye");
rbytes=recv(clientSocket,rbuff,sizeof(rbuff),0);
if(rbytes==-1)
{perror("error in reading choice");
return false;}
int choice=atoi(rbuff);

switch (choice){
        case 1:
         if(account_bal(clientSocket))
       // {
       // send(clientSocket,"successfuly added\npress enter to continue\n",strlen("successfully added\npress enter to continue\n"),0);
       // }
        break;
        case 2:
                if(deposit(clientSocket))
        {send(clientSocket,"successfully deposit\n",strlen("successfully deposit\n"),0);}
        break;
      /* case 3:
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
                    break;*/
}printf("out of switch\n");
fflush(stdout);
}//while end
}//authenticate end
}//admin login end

bool authenticate_customer(int clientSocket)
{
send(clientSocket,"hi\n",strlen("hi\n"),0);
printf("hi\n");
char cid[50];
char password[10];
write(clientSocket,"id:\n",strlen("id:\n"));
ssize_t read1=read(clientSocket,cid,sizeof(cid));
if (read1<=0)
{
close (clientSocket);
return 0;
}
if(cid[read1 -1]=='\n')
{cid[read1 -1]='\0';}
else
{cid[read1 -1]='\0';}
write(clientSocket, "enter password:\n",strlen("enter password:\n"));
read1=read(clientSocket,password,sizeof(password));
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
int db_fd = open("customer.txt", O_RDONLY);
    if (db_fd == -1) {
        perror("Error in opening the database file");
        return false;
    }

    char line[300];
    struct customer temp;
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
                sscanf(line, "%[^,],%[^,],%[^,],%[^,],%d", temp.id, temp.password, temp.username,temp.bal, &temp.active);
                //temp.active = (is_active_int != 0); 
                printf("Read customer: ID=%s, Password=%s, Name=%s,Balance=%s, Active=%d\n", temp.id, temp.password, temp.username,temp.bal,temp.active);


           // sscanf(line, "%[^,],%[^,],%[^,],%[^,]", temp.id, temp.password, temp.username, &temp.role);
           // printf("Read Employee: ID=%s, Name=%s, Password=%s, Role=%s\n", temp.id, temp.password, temp.username, temp.role);
printf("%s,%s\n",temp.id,cid);

            if (atoi(temp.id)==atoi( cid)&& atoi(temp.password)==atoi(password)&&temp.active==1) {
                printf("Employee ID matched.\n");return true;}
   }//end of else
}//end of while

}//end of authenticate

bool account_bal(int clientSocket)
{
char cid[50];
char password[10];
write(clientSocket,"id:\n",strlen("id:\n"));
ssize_t read1=read(clientSocket,cid,sizeof(cid));
if (read1<=0)
{
close (clientSocket);
return 0;
}
if(cid[read1 -1]=='\n')
{cid[read1 -1]='\0';}
else
{cid[read1 -1]='\0';}
int db_fd = open("customer.txt", O_RDONLY);
    if (db_fd == -1) {
        perror("Error in opening the database file");
        return false;
    }

    char line[300];
    struct customer temp;
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
                sscanf(line, "%[^,],%[^,],%[^,],%[^,],%d", temp.id, temp.password, temp.username,temp.bal, &temp.active);
                //temp.active = (is_active_int != 0); 
                printf("Read customer: ID=%s, Password=%s, Name=%s,Balance=%s, Active=%d\n", temp.id, temp.password, temp.username,temp.bal,temp.active);


           // sscanf(line, "%[^,],%[^,],%[^,],%[^,]", temp.id, temp.password, temp.username, &temp.role);
           // printf("Read Employee: ID=%s, Name=%s, Password=%s, Role=%s\n", temp.id, temp.password, temp.username, temp.role);
printf("%s,%s\n",temp.id,cid);

            if (atoi(temp.id)==atoi( cid)) {
                write(clientSocket,temp.bal,sizeof(temp.bal));return true;}
   }//end of else
}//end of while


}//end of account_bal

bool deposit(int cd)
{
struct transaction add;
//int empid=get_id();
//add.id=empid;
write(cd,"enter senderid\n",strlen("enter senderid\n"));
int read1=read(cd,add.sender,sizeof(add.sender));
add.sender[read1 -1]='\0';
write(cd,"enter receiver\n",strlen("enter receiver\n"));
 read1=read(cd,add.rec,sizeof(add.rec));
//add.id[read -1]='\0';
if(read1<=0)
{send(cd,"error in receiver\n",strlen("error in receiver\n"),0);
return false;}
add.rec[read1-1]='\0';
write(cd,"enter amount\n",strlen("enter amount\n"));
read1=read(cd,add.amount,sizeof(add.amount));
int amount=atoi(add.amount);printf("amounttran%d\n",amount);
if(read1<=0)
{send(cd,"error in amount\n",strlen("error in amount\n"),0);
return false;}
add.amount[read1-1]='\0';

//send(clientSocket,"enter initial balance of customer\n",strlen("enter initial balance of customer\n"),0);
//read1=recv(clientSocket,add.bal,sizeof(add.bal),0);
//if(read<=0)
//{send(clientSocket,"error in fetching bal\n",strlen("error in fetching bal\n"),0);
//return false;}
strcpy(add.flag, "1");

//add.flag[read1-1]='\0';
//add.active=true;
FILE *file=fopen("transaction.txt","a");
if(file!=NULL)
{fprintf(file,"%s,%s,%s,%s\n",add.sender,add.rec,add.amount,add.flag);
fclose(file);
printf("true\n");
fflush(stdout);
}
else{
perror("can not open employee file");
printf("false\n");
fflush(stdout);
return false;
}

struct customer data_new;
        char cid[10];
        char format[300];
        char enter_id[] = "Enter sender id:";

        write(cd, enter_id, sizeof(enter_id));
        ssize_t bytes_id = read(cd, cid, sizeof(cid));
        if (bytes_id == -1) {
                perror("Error in receiving customer id");
                return false;
        }
        cid[bytes_id] = '\0';  
        printf("Received customer id: %s\n", cid);

        int db_fd = open("customer.txt", O_RDWR);
        if (db_fd == -1) {
                perror("Error in opening the customer file");
                return false;
        }

        char line[300];
        struct customer temp;
        bool is_there = false;

        struct flock lock;
        memset(&lock, 0, sizeof(lock));
        lock.l_type = F_WRLCK;  
        lock.l_whence = SEEK_SET;  

        //off_t record_offset = 0;
        off_t current_position = 0;

         char buffer;
        int line_index = 0;

        while (read(db_fd, &buffer, 1) > 0) {
        if (buffer != '\n') {
            line[line_index++] = buffer;
        }
         else {
                line[line_index] = '\0';
                line_index = 0;

                current_position = lseek(db_fd, 0, SEEK_CUR);

                int is_active_int;
                sscanf(line, "%[^,],%[^,],%[^,],%[^,],%d", temp.id, temp.password, temp.username,temp.bal, &is_active_int);
                temp.active = (is_active_int != 0); 
                printf("Read customer: ID=%s, Password=%s, Name=%s,Balance=%s, Active=%d\n", temp.id, temp.password, temp.username,temp.bal,temp.active);

                if (atoi(temp.id)==atoi( cid)) {
                        printf("customer is matched.\n");

                lock.l_start = current_position - strlen(line) - 1;  
                lock.l_len = strlen(line) + 1; 

                if (fcntl(db_fd, F_SETLKW, &lock) == -1) {
                         perror("Error in obtaining lock");
                        close(db_fd);
                        return false;
                }

                //write(cd, "username:", strlen("username:"));
              //ssize_t read1=  read(cd, data_new.username, sizeof(data_new.username));
		//if(read1<=0)
//{
		//close(cd);exit(1);}
		//if(data_new.username[read1 -1]=='\n')
		//	data_new.username[read1 -1]='\0';
		//else
		//	data_new.username[read1]='\0';
                 //write(cd, "cid", strlen("cid"));
               // ssize_t data_read = read(cd,data_new.id,sizeof(data_new.id));

               // if (data_read <= 0)
                //{
                  //      close(cd);
                    //    exit(1);
               // }

               // if(data_new.id[data_read-1]=='\n')
                 //       data_new.id[data_read-1]='\0';
                //else    
                  //      data_new.id[data_read]='\0';
		int new_bal=amount+atoi(temp.bal);
		sprintf(data_new.bal, "%d", new_bal);
		printf("%s\n",data_new.bal);
                snprintf(format, sizeof(format), "%s,%s,%s,%s,%d\n", temp.id, temp.password, temp.username,data_new.bal,temp.active);

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

}// end of deposit

