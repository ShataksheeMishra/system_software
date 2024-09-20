#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

int main()
{
struct rlimit  old;
if (getrlimit(RLIMIT_CPU, &old) == -1)
err(EXIT_FAILURE, "prlimit-1");
printf("Previous limits: soft=%jd; hard=%jd\n",
(intmax_t) old.rlim_cur, (intmax_t) old.rlim_max);
old.rlim_cur = 8 * 1024 * 1024;
old.rlim_max = 16 * 1024 * 1024;
if(setrlimit(RLIMIT_CPU, &old) == -1)
err(EXIT_FAILURE, "prlimit-2");
printf("New limits: soft=%jd; hard=%jd\n",
(intmax_t) old.rlim_cur, (intmax_t) old.rlim_max);

}
