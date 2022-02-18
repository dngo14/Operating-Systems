#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>

int main() {
    int fd;    /* to hold a file descriptor value */
    char buff[100];  /* to hold bytes read from an existing file myfile.txt */
    int ret;   /* a system call return value */

    if ((fd = open("myfile.txt", O_RDONLY)) < 0) {
        perror("open");
        return -1;
    }
    if ((ret = read(fd, buff, 5)) < 0) {
        perror("write");
        return -1;
    } 

    buff[ret] = '\0';  /* append a nullbyte, for printing */
    printf("read(%d, buff, 5) returned %d, and buff contains '%s'\n",
        fd, ret, buff);
}

