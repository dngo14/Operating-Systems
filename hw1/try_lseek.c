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
    int offset; //the offset

    if ((fd = open("myfile2.txt", O_WRONLY)) < 0) {
        perror("open");
        return -1;
    }
    if ((offset = lseek(fd, 10, SEEK_SET)) < 1) {
        perror("lseek");
        return -1;
    }
    printf("lseek(fd, 10, SEEK_SET) returned %d\n", offset);
    if ((ret = write(fd, "XYZ", 3)) < 0) {
        perror("write");
        return -1;
    }
    printf("write(%d, \"XYZ\", 3) returned %d\n", offset, ret);
    if ((offset = lseek(fd, 30, SEEK_SET)) < 1) {
        perror("lseek");
        return -1;
    }
    printf("lseek(fd, 10, SEEK_SET) returned %d\n", offset);
    if ((ret = write(fd, "ABC", 3)) < 0) {
        perror("write");
        return -1;
    }
    printf("write(%d, \"ABC\", 3) returned %d\n", offset, ret);

    buff[ret] = '\0';  /* append a nullbyte, for printing */

}