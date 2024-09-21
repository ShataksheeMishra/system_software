/*
============================================================================
Name : 18.c
Author : Shatakshee Mishra
Description :. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
int pipefd1[2];
int pipefd2[2]; 
pid_t pid1, pid2, pid3;

   pipe(pipefd1);
   pipe(pipefd2);

   
    pid1 = fork();
    if (pid1 == 0) {
     dup2(pipefd1[1], STDOUT_FILENO); 

   
        close(pipefd1[0]);
        close(pipefd1[1]);

        close(pipefd2[0]);
        close(pipefd2[1]);

        execlp("ls", "ls", "-l", NULL);

    }


    pid2 = fork();
  

    if (pid2 == 0) {
    dup2(pipefd1[0], STDIN_FILENO);
    dup2(pipefd2[1], STDOUT_FILENO);

    close(pipefd1[0]);
        close(pipefd1[1]);

        close(pipefd2[0]);
        close(pipefd2[1]);

        
        execlp("grep", "grep", "^d", NULL);
    }


    pid3 = fork();
    if (pid3 == 0) {
        dup2(pipefd2[0], STDIN_FILENO);
        close(pipefd1[0]);
        close(pipefd1[1]);
        
        close(pipefd2[0]);
        close(pipefd2[1]);
        execlp("wc", "wc", "-l", NULL);
 
    }

 
    close(pipefd1[0]);
    close(pipefd1[1]);
    close(pipefd2[0]);
    close(pipefd2[1]);

 
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}

