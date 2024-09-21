#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
char buffer[100];
mkfifo("file21a", 0666);
mkfifo("file21b", 0666);
int write_fd = open("file21a", O_WRONLY);
int read_fd = open("file21b", O_RDONLY);
while (1) {
printf("file21a: Enter a message: ");
fgets(buffer, sizeof(buffer), stdin);
write(write_fd, buffer, strlen(buffer) + 1);
if (strncmp(buffer, "exit", 4) == 0) {
break;
}
read(read_fd, buffer, sizeof(buffer)); 
printf("file21b says: %s", buffer);
if (strncmp(buffer, "exit", 4) == 0) {
break;
}
}
close(write_fd);
close(read_fd);
return 0;
}

