#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
pid_t pid = fork();

if (pid == 0) {

printf("Child  %d\n", getpid());
printf("killing parent %d \n", getppid());
kill(getppid(), SIGKILL);

sleep(5);
printf("Child  %d is now orphan, parent pid is %d\n", getpid(),getppid());

} else {
printf("Parent  %d is alive.\n", getpid());
sleep(5);
}
return 0;
}

/*output
shatakshee@shatakshee:~/ss/hands-on-list2$ ./a.out
Parent  5558 is alive.
Child  5559
killing parent 5558 
Killed
shatakshee@shatakshee:~/ss/hands-on-list2$ Child  5559 is now orphan, parent pid is 1489
*/
