#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp) {
    int ret;

    if((ret = symlink(argv[1], argv[2])) < 0) {
        perror("symlink()");
        return -1;
    }

    return 0;
}