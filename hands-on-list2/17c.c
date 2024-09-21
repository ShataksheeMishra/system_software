/*
============================================================================
Name : 17c.c
Author : Shatakshee Mishra
Description :Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl 
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
int pipefd[2]; 
pid_t pid1, pid2;
pipe(pipefd);
pid1 = fork();
if (pid1 == 0) {
close(STDOUT_FILENO);
fcntl(pipefd[1],F_DUPFD,STDOUT_FILENO);
close(pipefd[0]);
close(pipefd[1]);
execlp("ls", "ls", "-l", NULL);
}
pid2 = fork();
if (pid2 == 0) {
close(STDIN_FILENO);
fcntl(pipefd[0],F_DUPFD,STDIN_FILENO);
close(pipefd[0]);
close(pipefd[1]);
execlp("wc", "wc", NULL);
}
close(pipefd[0]);
close(pipefd[1]);
waitpid(pid1, NULL, 0);
waitpid(pid2, NULL, 0);
return 0;
}
