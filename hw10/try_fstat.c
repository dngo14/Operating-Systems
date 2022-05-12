#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>

int main(int argc, char **argv, char **envp) {
    int ret;
    int fd;

    if ((fd = open("myfile.txt", O_RDONLY)) < 0) {
        perror("open");
        return -1;
    }

    struct stat *buf;

    if ((ret = fstat(fd, buf)) < 0) {
        perror("fstat");
        return -1;
    }

    printf("The Device ID is %d\nThe File Serial Number is %d\nThe Mode of File is %d\n", buf->st_dev, buf->st_ino, buf->st_mode);

    return 0;
}