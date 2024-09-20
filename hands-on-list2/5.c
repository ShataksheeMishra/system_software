#include<unistd.h>
#include<stdio.h>
void main()
{
long val;
val=sysconf(_SC_ARG_MAX);
printf("Maximum length of the arguments to the exec family of functions: %ld\n", val);
val = sysconf(_SC_CHILD_MAX);
printf("Maximum number of simultaneous process per user id : %ld\n", val);
val = sysconf(_SC_CLK_TCK);
printf("Number of clock ticks (jiffy) per second :%ld\n", val);
val = sysconf(_SC_OPEN_MAX);
printf("Maximum number of open files :%ld\n", val);
val = sysconf(_SC_PAGESIZE);
printf("Size of a page :%ld bytes\n", val);
val = sysconf(_SC_PHYS_PAGES);
printf("Total number of pages in the physical memory :%ld\n", val);
val = sysconf(_SC_AVPHYS_PAGES);
printf("Number of  currently available pages in the physical memory :%ld\n", val);
}
