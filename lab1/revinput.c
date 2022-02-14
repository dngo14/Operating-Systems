#include <stdio.h>
#include <stdlib.h> 

int main() { 
    // char *ptr = (char*) malloc(50);
    
    // scanf("%s", ptr);
    // int a = sizeof(ptr);
    // scanf("%s", ptr+a);
    // int b = sizeof(ptr)+sizeof(ptr+a);
    // scanf("%s", ptr+b);
    // int c = sizeof(ptr)+sizeof(ptr+a)+sizeof(ptr+b);
    // scanf("%s", ptr+c);
    // int d = sizeof(ptr)+sizeof(ptr+a)+sizeof(ptr+b)+sizeof(ptr+c);
    // scanf("%s", ptr+d);
    
    // printf("%s\n", ptr+d);
    // printf("%s\n", ptr+c);
    // printf("%s\n", ptr+b);
    // printf("%s\n", ptr+a);
    // printf("%s\n", ptr);
    // free(ptr);

    char **arr = (char**) malloc(sizeof(char*[5]));
    char array1[11];
    char array2[11];
    char array3[11];
    char array4[11];
    char array5[11];
    arr[0] = array1;
    arr[1] = array2;
    arr[2] = array3;
    arr[3] = array4;
    arr[4] = array5;
    scanf("%s", arr++);
    scanf("%s", arr++);
    scanf("%s", arr++);
    scanf("%s", arr++);
    scanf("%s", arr);
    
    printf("%s\n", arr--);
    printf("%s\n", arr--);
    printf("%s\n", arr--);
    printf("%s\n", arr--);
    printf("%s\n", arr);

    free(arr);
}