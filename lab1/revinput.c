#include <stdio.h>
#include <stdlib.h> 

int main() { 
    char *ptr = (char*) malloc(50);
    scanf("%s", ptr);
    int a = sizeof(ptr);
    scanf("%s", ptr+a);
    int b = sizeof(ptr)+sizeof(ptr+a);
    scanf("%s", ptr+b);
    int c = sizeof(ptr)+sizeof(ptr+a)+sizeof(ptr+b);
    scanf("%s", ptr+c);
    int d = sizeof(ptr)+sizeof(ptr+a)+sizeof(ptr+b)+sizeof(ptr+c);
    scanf("%s", ptr+d);
    
    printf("%s\n", ptr+d);
    printf("%s\n", ptr+c);
    printf("%s\n", ptr+b);
    printf("%s\n", ptr+a);
    printf("%s\n", ptr);
    free(ptr);
}