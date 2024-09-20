#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void handler(int sig) {
    printf(" Segmentation Fault\n");
    exit(1);
}

int main() {
    
struct sigaction sa;
memset(&sa, 0, sizeof(sa));
sa.sa_handler = handler;
sigaction(SIGSEGV, &sa, NULL);
int *ptr = NULL;
*ptr = 42;
return 0;

}
