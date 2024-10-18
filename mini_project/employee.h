#ifndef EMPLOYEE
#define EMPLOYEE
bool employee_login(int clientSocket);
struct employee
{char id[20];
char username[50];
char password[10];
char role[20];
};
#endif
