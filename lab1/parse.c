#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <cstring>

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

int main() {
    char *line = (char*) malloc(80);
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
    //token = get_token(&line, &status);
    // while (status != 1) {
    //     if (token == NULL) {
    //         printf("get_token() returned NULL\n");
    //         break;
    //     }
    //     else {
    //         arr[count] = token;
    //         //printf("status %d.  line[] now contains '%s'\n", status, line);
    //         count+=1;
    //         token = get_token(&line, &status);
    //         printf("get_token() returned '%s'\n", token);
    //     }
    // }
    while (count < 5) {
        token = get_token(&line, &status);
        printf("get_token() returned '%s'\n", token);
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
        arr[count] = (char*)0;
        printf("Final Status is %d \n", status);
        printf("The Array Contains %d Elements:\n", count);
        for (int i = 0; i < count; i++) {
            printf("\t%d: %s\n", i, arr[i]);
        }
      
    free(token);
    free(arr);
    return 0; 
}