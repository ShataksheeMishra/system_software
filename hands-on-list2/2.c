#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>
#include<stdint.h>
#include<time.h>
int main()
{struct rlimit limit;
int a=getrlimit(RLIMIT_CPU,&limit);
printf("limits:\n soft:%jd\n hard:%jd\n",(intmax_t) limit.rlim_cur,(intmax_t) limit.rlim_max);
}
