
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
int pipefd[2];
pid_t cpid;
char buff;
char s[80];
pipe(pipefd);
cpid = fork();
if (cpid == 0)
{ /* Child reads from pipe */
sleep(5);
close(pipefd[1]); /* Close unused write end */
// display from kernal using pipes reading end in child
printf(" write child \n");
while (read(pipefd[0], &buff, 1) > 0)
write(1, &buff, 1);
write(1, "\n", 1);
close(pipefd[0]); /* Close unused read end */
}
else
{ /* Parent writes argv[1](message) to pipe*/
printf("writing in pipe from parent process\n");
scanf("%s", s);
close(pipefd[0]); /* Close unused read end */
write(pipefd[1], s, sizeof(s));
close(pipefd[1]); /* Reader will see EOF */
wait(0);          /* Wait for child */
    }
}

/*output
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
writing in pipe from parent process
hello
 write child 
hello
*/
