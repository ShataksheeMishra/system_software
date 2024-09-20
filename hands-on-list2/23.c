#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>
void main()
{
long maxFile;
long pipesize; 
char *s = "23_fifo";
mkfifo(s, S_IRWXU);
maxFile = sysconf(_SC_OPEN_MAX);
printf("Maximum number of files that can be opened is: %ld\n", maxFile);
printf(" Size of pipe: %d\n", PIPE_BUF);
}
