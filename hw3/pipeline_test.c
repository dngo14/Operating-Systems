#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp) {
    int fd[2];
    int ret, ret2, ret3, fork1, fork2, closereturn1, closereturn2, closereturn3, closereturn4, closereturn5, closereturn6;

    if ((ret = pipe(fd)) < 0) {
        perror("pipe() failed");
        return -1;
    }


    if ((fork1 = fork()) < 0) {
        printf("fork() FAILED");
        perror("forkeg");
        _exit(1);
    }
    /* fork() succeeded */
    if (fork1 != 0) {
    
    /* NOTE: parent should ordinarily wait(), to collect child's exit status */
    } else {
        int dup1;

        if ((closereturn3 = close(1)) < 0) {
            perror("close");
            return -1;
        }

        dup1 = dup(fd[1]);

        if ((closereturn4 = close(fd[0])) < 0) {
            perror("close");
            return -1;
        }

        if ((closereturn4 = close(fd[1])) < 0) {
            perror("close");
            return -1;
        }

        char *arg[3];
        arg[0] = "cat";
        arg[1] = "execve_test.c";
        arg[2] = NULL;

        if ((ret2 = execve("/bin/cat", arg, envp)) < 0) {
            perror("execve");
            return -1;
        }
        _exit(1);
    }


    if ((fork2 = fork()) < 0) {
        printf("fork() FAILED");
        perror("forkeg");
        _exit(1);
    }
    /* fork() succeeded */
    if (fork2 != 0) {
        if ((closereturn1 = close(fd[0])) < 0) {
            perror("close");
            return -1;
        }
        if ((closereturn2 = close(fd[1])) < 0) {
            perror("close");
            return -1;
        }
        wait(NULL);
        wait(NULL);

    /* NOTE: parent should ordinarily wait(), to collect child's exit status */
    } else {
        int dup2;

        if ((closereturn5 = close(0)) < 0) {
            perror("close");
            return -1;
        }

        dup2 = dup(fd[0]);

        if ((closereturn6 = close(fd[0])) < 0) {
            perror("close");
            return -1;
        }

        if ((closereturn6 = close(fd[1])) < 0) {
            perror("close");
            return -1;
        }

        char *arg[2];
        arg[0] = "sort";
        arg[1] = NULL;

        if ((ret3 = execve("/bin/sort", arg, envp)) < 0) {
            perror("execve");
            return -1;
        }
        _exit(1);
    }

}