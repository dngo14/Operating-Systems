#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>

int main(int argc, char **argv, char **envp) {

    int ret, ret2;
    int dup1;
    int closereturn, closereturn2;

    if ((closereturn = close(1)) < 0) {
        perror("close");
        return -1;
    }

    if ((ret2 = open("ls.out", O_WRONLY)) < 0) {
        perror("open() failed");
        return -1;
    }

    dup1 = dup(ret2);

    // if ((closereturn2 = close(ret2)) < 0) {
    //     perror("close");
    //     return -1;
    // }

    if ((ret = execve("/bin/ls", argv, envp)) < 0) {
        perror("execve");
        return -1;
    }

    // if ((closereturn = close(1)) < 0) {
    //     perror("close");
    //     return -1;
    // }

    // if ((ret2 = open("ls.out", O_WRONLY)) < 0) {
    //     perror("open() failed");
    //     return -1;
    // }


    // if ((ret3 = write(dup1, envp, 100)) < 0) {
    //     perror("write() failed");
    //     return -1;
    // }

    return 0;
}