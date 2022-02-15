#include <stdio.h>
#include <stdlib.h>  

int main() {
    char *buff = (char*) malloc(12);
    size_t size = 12;
    int returns = getline(&buff, &size, stdin);
    printf("%d\n", returns);
    printf("%d\n", buff);

    // int count = 0;
    // while(*buff++ != '\0') {
    //     count++;
    // }
    printf("%d\n", size);
    free(buff);
    //free(buff-count-1);
}