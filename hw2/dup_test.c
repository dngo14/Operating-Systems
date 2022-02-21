#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>

int main() {
    int fd, fd2;
    fd = open("myfile.txt", O_RDONLY); 
    fd2 = dup(fd);

    char buff[20];
    read(fd, buff, 2);  /* stores  He  in buff */
    buff[2] = '\0';
    printf("First read returned %s\n", buff);

    read(fd2, buff, 6);  /* stores  llo, w  in buff */
    buff[6] = '\0';
    printf("Second read returned %s\n", buff);

    read(fd, buff, 2);  /* stores  or  in buff */
    buff[2] = '\0';
    printf("Third read returned %s\n", buff);

    lseek(fd2, 1, SEEK_SET);
    read(fd, buff, 2);  /* stores  el  in buff */
    buff[2] = '\0';
    printf("Fourth read returned %s\n", buff);

}