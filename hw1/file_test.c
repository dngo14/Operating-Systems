#include <stdio.h>
#include <stdlib.h>    /* for strtol() */
#include <sys/stat.h>  
#include <sys/types.h>
//#include <errno.h>
#include <fcntl.h>


int main(int argc, char **argv) {
    if (argc != 2) {
    printf("%s:  expects 1 arguments, exiting\n", argv[0]);
    return -1;
    }

    int ret;
    //int howtoopen = O_RDWR;
    //ret = open(argv[1], O_RDONLY);
    //int howtoopen = strtol("O_RDWR", NULL, 8);

    if ((ret = open(argv[1], O_RDWR)) < 0) {
        perror("open() failed");
        return -1;
    }
    printf("open() returned %d\n", ret);

    int ret2;
    char arrayofbytes[10];

    ret2 = read(ret, arrayofbytes, 2);

    if (ret2 < 0) {
        perror("read() failed");
        return -1;
    }
    arrayofbytes[2] = '\0';
    printf("read() returned %d\n", ret2);
    printf("read obtained the characters %s\n", arrayofbytes);
    
    int ret3;
    char arrayofbytes2[] = "ABCD";

    if ((ret3 = write(ret, arrayofbytes2, 4)) < 0) {
        perror("write() failed");
        return -1;
    }

    printf("write() returned %d\n", ret3);

    int ret4;
    if ((ret4 = close(ret)) < 0) {
        perror("close() failed");
        return -1;
    }

    printf("close() returned %d\n", ret4);


    return 0;


}