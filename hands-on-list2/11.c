#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    int status;

    printf("ignoring the SIGINT signal for 5 seconds\n");
    struct sigaction act;

    act.sa_handler = SIG_IGN; // Ignoring SIGINT
    act.sa_flags = 0;
    status = sigaction(SIGINT, &act,NULL);
        sleep(5);

    printf("reseting the default action of the SIGINT signal\n");
    struct sigaction actdefault;

    actdefault.sa_handler = SIG_DFL; // setting default SIGINT
    actdefault.sa_flags = 0;
    status = sigaction(SIGINT, &actdefault,NULL);
        sleep(5);
}
