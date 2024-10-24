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
#include "loan.h"
bool employee_login(int clientSocket);
bool authenticate_emp(int clientSocket);
bool add_customer(int cd);
bool process_loan(int clientSocket);
bool modify_customer(int clientSocket);
bool process_loan(int clientSocket);
bool view_loan( int clientSocket);
bool change_password(int clientSocket);
bool employee_login(int clientSocket)
{printf("hello\n");
send(clientSocket,"hello\n",strlen("hello\n"),0);

if(authenticate_emp(clientSocket))

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

switch (choice){
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
                if(process_loan(clientSocket))
        {send(clientSocket,"success\n",strlen("success\n"),0);}
        break;
	case 4:
		if(view_loan(clientSocket))		
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
}printf("out of switch\n");
fflush(stdout);
}//while end
}//authenticate end
}//admin login end
bool authenticate_emp(int clientSocket)
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
             printf("Read Employee: ID=%s, Password=%s, Username=%s, Role=%s\n", temp.id, temp.password, temp.username, temp.role);
printf("%s,%s\n",temp.id,empid);

            if (atoi(temp.id)==atoi( empid)&& atoi(temp.password)==atoi(password)) {
                printf("Employee ID matched.\n");return true;}
   }//end of else
}//end of while

}//end of authenticate

bool add_customer(int clientSocket)
{struct customer add;
//int empid=get_id();
//add.id=empid;
write(clientSocket,"enter coustmerid\n",strlen("enter customerid\n"));
int read1=read(clientSocket,add.id,sizeof(add.id));
add.id[read1 -1]='\0';
write(clientSocket,"enter username\n",strlen("enter username\n"));
 read1=read(clientSocket,add.username,sizeof(add.username));
//add.id[read -1]='\0';
if(read1<=0)
{write(clientSocket,"error in fetching username\n",strlen("error in fetching username\n"));
return false;}
add.username[read1-1]='\0';
write(clientSocket,"enter password\n",strlen("enter password\n"));
read1=read(clientSocket,add.password,sizeof(add.password));
if(read1<=0)
{write(clientSocket,"error in fetching password\n",strlen("error in fetching password\n"));
return false;}
add.password[read1-1]='\0';

write(clientSocket,"enter initial balance of customer\n",strlen("enter initial balance of customer\n"));
read1=read(clientSocket,add.bal,sizeof(add.bal));
if(read<=0)
{write(clientSocket,"error in fetching bal\n",strlen("error in fetching bal\n"));
return false;}
add.bal[read1-1]='\0';
add.active=true;
FILE *file=fopen("customer.txt","a");
if(file!=NULL)
{fprintf(file,"%s,%s,%s,%s,%d\n",add.id,add.password,add.username,add.bal,add.active);
fclose(file);
printf("true\n");
fflush(stdout);
return true;}
perror("can not open employee file");
printf("false\n");
fflush(stdout);
return false;
}//end of add_customer

bool modify_customer(int cd)
{
struct customer data_new;
        char cid[10];
        char format[300];
        char enter_id[] = "Enter customer id:";

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

                write(cd, "username:", strlen("username:"));
              ssize_t read1=  read(cd, data_new.username, sizeof(data_new.username));
		if(read1<=0)
{
		close(cd);exit(1);}
		if(data_new.username[read1 -1]=='\n')
			data_new.username[read1 -1]='\0';
		else
			data_new.username[read1]='\0';
                 write(cd, "cid", strlen("cid"));
                ssize_t data_read = read(cd,data_new.id,sizeof(data_new.id));

                if (data_read <= 0)
                {
                        close(cd);
                        exit(1);
                }

                if(data_new.id[data_read-1]=='\n')
                        data_new.id[data_read-1]='\0';
                else    
                        data_new.id[data_read]='\0';


                snprintf(format, sizeof(format), "%s,%s,%s,%s,%d\n", data_new.id, temp.password, data_new.username,temp.bal,temp.active);

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
}//end of modify customer






bool change_password(int cd)
{printf("inside change password\n");
struct employee data_new;
    char empid[10];
	char password[10];
    char format[300];
    char enter_id[] = "enter id";

    write(cd, enter_id, sizeof(enter_id));
    ssize_t bytes_id = read(cd, empid, sizeof(empid));
    if (bytes_id == -1) {
        perror("Error in receiving Employee ID");
        return false;
    }
    printf("Received Employee ID: %s\n", empid);
write(cd, "old password\n", strlen("old password\n"));
     bytes_id = read(cd, password, sizeof(password));
    if (bytes_id == -1) {
        perror("Error in receiving password");
        return false;
    }
    printf("password: %s\n", password);


    write(cd, "new password:", strlen("new password:"));
    read(cd, data_new.password, sizeof(data_new.password));
	printf("pass=%s",data_new.password);
    //write(cd, "ID:", strlen("ID:"));
    //read(cd, data_new.id, sizeof(data_new.id));
	//write(cd,"role",strlen("role"));
	//read(cd,data_new.role,sizeof(data_new.role));

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
            printf("Read Employee: ID=%s, password=%s, username=%s, Role=%s\n", temp.id, temp.password, temp.username, temp.role);
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
		printf("%s",data_new.password);
                //strcpy(data_new.password, temp.password);  
 if (atoi(temp.id)==atoi( empid)&& atoi(temp.password)==atoi(password)){
                snprintf(format, sizeof(format), "%s,%s,%s,%s\n", temp.id, data_new.password, temp.username, temp.role);

                lseek(db_fd, current_position - strlen(line) - 1, SEEK_SET);
		printf("%s",data_new.password);
                if (write(db_fd, format, strlen(format)) == -1) {
                    write(cd, "Error in Updating Data", strlen("Error in Updating Data"));
                    close(db_fd);
                    return false;
                }
		printf("updated");
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
    }

    close(db_fd);

    if (!is_there) {
        write(cd, "Employee Not Found", strlen("Employee Not Found"));
        return false;
    }

    return true;
}//end of change password
bool process_loan(int cd){
	struct loan data_new;
        char custid[10];
        char format[300];
        char enter_id[] = "Enter id of customer:";

        write(cd, enter_id, sizeof(enter_id));
        ssize_t bytes_id = read(cd, custid, sizeof(custid));
        if (bytes_id == -1) {
                perror("Error in receiving Customer ID");
                return false;
        }	
	
        custid[bytes_id] = '\0';  
        printf("*Received Customer ID: %s\n", custid);

	char ch[2];
        char ch_prompt[]="Press 1 to Approve 0 to Reject:";
	 write(cd, ch_prompt, sizeof(ch_prompt));
        ssize_t bytes_ch = read(cd, ch, sizeof(ch));
        if (bytes_ch == -1) {
                perror("Error");
                return false;
        }
        ch[bytes_ch] = '\0';  

        int db_fd = open("loan.txt", O_RDWR);
        if (db_fd == -1) {
                perror("Error in opening the database file");
                return false;
        }

        char line[300];
        struct loan temp;
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

                
                sscanf(line, "%[^,],%[^,],%d", temp.cid,temp.eid,&temp.stat);

                if (atoi(temp.cid)==atoi(custid) == 0) {
                        printf("Customer ID matched.\n");

                lock.l_start = current_position - strlen(line) - 1;  
                lock.l_len = strlen(line) + 1; 

                if (fcntl(db_fd, F_SETLKW, &lock) == -1) {
                         perror("Error in obtaining lock");
                        close(db_fd);
                        return false;
                }
		
		if(atoi(ch)==1){
			data_new.stat=2;
			write(cd,"Loan Approved\n",strlen("Loan Approved\n"));
		}
		else{
			data_new.stat=1;
                        write(cd,"Loan Rejected\n",strlen("Loan Rejected\n"));
                }
	

                snprintf(format, sizeof(format), "%s,%s,%d\n", temp.cid, temp.eid, data_new.stat);

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
                write(cd, "Customer Not Found", strlen("Customer Not Found"));
                return false;
        }

        return true;

}//end of process_loan

bool view_loan(int cd)
{
struct loan data_new;
        char emplid[10];
        char format[300];
        char enter_id[] = "Enter Your ID:";

        write(cd, enter_id, sizeof(enter_id));
        ssize_t bytes_id = read(cd, emplid, sizeof(emplid));
        if (bytes_id == -1) {
                perror("Error in receiving Employee ID");
                return false;
        }
        emplid[bytes_id] = '\0';  
        printf("Received Employee ID: %s\n", emplid);

        int db_fd = open("loan.txt", O_RDWR);
        if (db_fd == -1) {
                perror("Error in opening the database file");
                return false;
        }
	 char buffer;
        int line_index = 0;
	char transaction_buffer[500];

	char line[300];
        struct loan temp;
        bool is_there = false;
	off_t current_position = 0;
	

	while (read(db_fd, &buffer, 1) > 0) {
        if (buffer != '\n') {
            line[line_index++] = buffer;
        }

         else {
                line[line_index] = '\0';
                line_index = 0;

                current_position = lseek(db_fd, 0, SEEK_CUR);

                sscanf(line, "%[^,],%[^,],%d", temp.cid,temp.eid,&temp.stat);
                printf("Read Customer: ID=%s, Employee= %s, status=%d\n", temp.cid,temp.eid,&temp.stat);

                if (atoi(temp.eid)==atoi(emplid)) {
                        printf("Employee ID matched.\n");

		char temp1[256];
                snprintf(temp1, sizeof(temp1), "CID: %s\n",temp.cid);
		
		 strcat(transaction_buffer, temp1);
		continue;            
		

                }

         
            }}
	    if(transaction_buffer!=NULL){
	    write(cd,transaction_buffer,strlen(transaction_buffer));
	   return true;

        	}
	    else
		write(cd,"No Loan Applications Assigned\n",strlen("No Loan Applications Assigned\n"));
		return false;
	
//return true;
}


