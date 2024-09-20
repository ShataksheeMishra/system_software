#include <stdio.h>
#include <stdlib.h>

int main() {
system("mknod myfifo_a p");
printf("FIFO file is created.\n");
return 0;
}
