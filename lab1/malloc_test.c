#include <stdio.h>
#include <stdlib.h>  

int main() { 
    char *ptr = (char*) malloc(11);
    scanf("%s", ptr);
    printf("%s\n", ptr);
    free(ptr);
}