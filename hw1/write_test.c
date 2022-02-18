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

    if ((fd = open("myfile.txt", O_WRONLY | O_APPEND)) < 0) {
        perror("open");
        return -1;
    }
    if ((ret = write(fd, "EFGH", 4)) < 0) {
        perror("write");
        return -1;
    } 

    buff[ret] = '\0';  /* append a nullbyte, for printing */
    printf("write(%d, \"EFGH\", 4) returned %d\n", fd, ret);
}

