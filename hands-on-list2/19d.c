#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
mknod("myfifo_d", S_IFIFO | 0666, 0);
printf("FIFO file created.\n");
return 0;
}
