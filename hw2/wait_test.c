#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp) {
    int ret, ret2;
    int status; 
    int cpid;  /* for holding child's PID */
    if ((ret = fork()) < 0) {
        perror("fork");
        return -1;
    }
    if (ret != 0) {/* parent */
        cpid = wait(&status);
    }else {/* child */
        //printf("Child pid=%d;  exit status is %d\n", cpid, status);
        if ((ret2 = execve("/bin/ls", argv, envp)) < 0) {
        perror("execve");
        return -1;}
    }

    /* parent */
    printf("Child pid=%d;  exit status is %d\n", cpid, status);
 
}