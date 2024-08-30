#include <stdio.h>
#include <unistd.h>
int main()
{char *path = "ls";
 char *argv[] = {path, "-Rl", NULL};
 execvp(path, argv);
}
