#ifndef ADMIN
#define ADMIN
struct Credentials
{
char username[50];
char password[10];
};

bool admin_login(int clientSocket);
bool authenticate_admin(int clientSocket);
bool change_pass(int clientSocket);
#endif
