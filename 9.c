/*
============================================================================
Name : 9.c
Author : Shatakshee Mishra
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

Date: 21st Aug, 2024.
============================================================================
*/
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
int main (int arg1,char *arg[])
{struct stat sb;
stat (arg[1],&sb);
printf("I-node number:%ju\n",  sb.st_ino);

           printf("Mode: %jo (octal)\n", sb.st_mode);

           printf("Link count:%ju\n",  sb.st_nlink);
           printf("Ownership:UID=%ju   GID=%ju\n", sb.st_uid, sb.st_gid);

           printf("Preferred I/O block size: %jd bytes\n",sb.st_blksize);
           printf("File size: %jd bytes\n", sb.st_size);
           printf("Blocks allocated: %jd\n",  sb.st_blocks);

           printf("Last status change: %s", ctime(&sb.st_ctime));
           printf("Last file access: %s", ctime(&sb.st_atime));
           printf("Last file modification:%s", ctime(&sb.st_mtime));



}

/*output
shatakshee@shatakshee:~/ss$ ./a.out foods
I-node number:787758
Mode: 100664 (octal)
Link count:2
Ownership:UID=1000   GID=1000
Preferred I/O block size: 4096 bytes
File size: 1214 bytes
Blocks allocated: 8
Last status change: Wed Aug 28 20:38:11 2024
Last file access: Fri Aug 30 14:41:42 2024
Last file modification:Wed Aug 28 20:38:11 2024
*/
