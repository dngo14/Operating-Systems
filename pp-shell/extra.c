#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char *get_token(char **ptr, int *status) {
    char *tok = (char*) malloc(80); //dynamic array
  
    while (isspace(**ptr) != 0) {
       *ptr+=1; //accumulate pointer when a space character
    }
    int count = 0; //counter
    while (isspace(**ptr) == 0) {
        tok[count++] = **ptr; //set elements to characters till it hits a space character
        *ptr+=1; //accumulate the pointer until it hits a space character
    }
    if (**ptr == ' ') {
        *status = 0; //last ptr at space
    } else if (**ptr == '\n') {
        *status = 1; //last ptr at new line
    } else {
        *status = 2; //last ptr at null byte
    }

    return tok;
}

int main(int argc, char **argv, char **envp) {
    int loop = 1; 
    while (loop == 1) { //loop for program
    char *line = (char*) malloc(80);
    char *baseline = line;
    size_t size = 80;
    int ret;  
    printf("Enter a line of input\n");
    if ((ret = getline(&line, &size, stdin)) < 0) {
        perror("getline");
        return -1;
    }

    char **arr = (char**) malloc(sizeof(char*[5]));
    int count = 0;
    char *token; 
    int status = 0;
    
    while (count < 5) {
        token = get_token(&line, &status);
        //printf("get_token() returned '%s'\n", token);
        arr[count] = token;
        count+=1;
        if (status == 1) {
            break;
        }
        if (count == 4) {
            printf("Error, Too Many Tokens; Only Four Will Be Recorded \n");
            break;
        }
    }

    int fd[2];

    if (pipe(fd) < 0 ) {
        perror( "pipe" );
        return -1;
    }


    int fork1;

    if ((fork1 = fork()) < 0) {
        printf("fork() FAILED");
        perror("forkeg");
        _exit(1);
    }

    if (fork1 != 0) {
        wait(NULL);
        printf("\nChild Process Exited Safely\n");

        if((close(fd[1])) < 0) {
            perror("close");
            return -1;
        }

        dup(fd[0]);
        char buffer[50];
        int n = read(fd[0], buffer, sizeof(buffer));

        if (buffer[0] != '\0') {
            if ((chdir(buffer)) < 0) {
                perror("chdir");
                return -1;
            }
        }

    } else {
        int ret2, fd2, dup1;

        //printf("Child Process Was A Success With An ID Of %d And Parent ID Of %d\n", getpid(), getppid());

        char output;
        printf("Do you want the output to be directed to an output file? \nType y or n \nResponse: ");
        scanf("%c", &output);

        if (output == 'y') {
            if ((fd2 = open("output.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) < 0) {
            perror("open");
            return -1;
            }

            if ((close(1)) < 0) {
                perror("close");
                return -1;
            }

            dup1 = dup(fd2);

            close(fd2); 

        }
        if (strcmp(arr[0], "exit") == 0) {
            kill(getppid(), SIGKILL);
            return -1;
        }
        
        if (strcmp(arr[0], "/bin/cd") == 0) {

            if ((close(fd[0])) < 0) {
                perror("close");
                return -1;
            }

            if ((close(1)) < 0) {
                perror("close");
                return -1;
            }

            dup(fd[1]);
            write(1, arr[1], 50);

        } else {
            if ((ret2 = execve(arr[0], arr, envp)) < 0) {
                perror("execve");
                return -1;
            }
        }

        _exit(1);
    }

    arr[count] = (char*)0;
    printf("Final Status is %d \n", status);
    printf("The Array Contains %d Elements:\n", count);
    for (int i = 0; i < count; i++) {
        printf("\t%d: %s\n", i, arr[i]);
    }
      
    free(token);
    free(arr);
    free(baseline);
    }
    return 0; 
}