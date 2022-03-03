#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>
#include <cstdlib>

int main(int argc, char **argv, char **envp) {
    char *arr = (char*) malloc(7);
    //char arr[7];
    printf("Enter a line of at least 7 characters: ");
    scanf("%s", arr);

    int fd[2], ret, ret2, ret3, ret4, ret5;
    //char firstthree[3];
    //char secondthree[3];
    char *firstthree = (char*) malloc(3);
    char *secondthree = (char*) malloc(3);

    if ((ret = pipe(fd)) < 0) {
        perror("pipe() failed");
        return -1;
    }

    if ((ret2 = write(fd[1], arr, 5)) < 0) {
        perror("write");
        return -1;
    } 

    if ((ret3 = read(fd[0], firstthree, 3)) < 0) {
        perror("write");
        return -1;
    } 

    printf("first three characters of the pipe buffer are \'%s\'\n", firstthree);

    if ((ret4 = write(fd[1], arr, 2)) < 0) {
        perror("write");
        return -1;
    } 

    if ((ret5 = read(fd[0], secondthree, 3)) < 0) {
        perror("write");
        return -1;
    }

    printf("second three characters are \'%s\'\n", secondthree); 

}