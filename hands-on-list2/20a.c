#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
char buff[80];
mkfifo("file20", 0744);
int fd = open("file20", O_WRONLY);
printf("%d\n", fd);
fgets(buff, 80,stdin);
write(fd,buff,sizeof(buff));
close(fd);
return 0;
}
