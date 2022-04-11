#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>

int main(int argc, char **argv, char **envp) {
    int ret;
    if((ret = unlink(argv[1])) < 0) {
        perror("unlink()");
        return -1;
    }

    return 0;
}    