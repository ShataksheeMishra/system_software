#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void handler(int sig) {
    printf(" SIGINT");
	exit(0);
}

int main() {
struct sigaction sa;
memset(&sa, 0, sizeof(sa));
sa.sa_handler = handler;
sigaction(SIGINT, &sa, NULL);
while (1);

return 0;
}
