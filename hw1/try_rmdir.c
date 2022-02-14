#include <stdio.h>
#include <stdlib.h>    /* for strtol() */
#include <sys/stat.h>  
#include <sys/types.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("%s:  expects 1 argument, exiting\n", argv[0]);
        return -1;
    }

    int ret;
    if ((ret = rmdir(argv[1])) < 0) {
        perror("rmdir() failed");
        return -1;
    }

    printf("rmdir() return %d\n", ret);

    return 0;
}