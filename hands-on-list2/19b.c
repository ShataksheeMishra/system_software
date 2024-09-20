#include <stdio.h>
#include <stdlib.h>

int main() {
system("mkfifo myfifo_b ");
printf("FIFO file is created.\n");
return 0;
}
