#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
int main() {
mkfifo("myfifo_e", 0666);
printf("FIFO file created.\n");
return 0;
}
