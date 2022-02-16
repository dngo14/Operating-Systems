#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <cstring>



char *get_token(char **ptr, int *status) {
    char *tok = (char*) malloc(80);
    //printf("%d\n", isspace(**ptr));
    //printf("%d\n", isspace(**ptr));
    while (isspace(**ptr) != 0) {
       *ptr+=1;
       //printf("%d\n", isspace(**ptr));
       //printf("%c\n", *ptr);
    }
    //printf("%c\n", **ptr);
    //printf("%d\n", isspace(**ptr));
    //*ptr+=1;
    //printf("%c\n", **ptr);
    // *tok = **ptr;
    // tok+=1;
    // *ptr+=1;
    // *tok = **ptr;
    int count = 0;
    while (isspace(**ptr) == 0) {
        tok[count++] = **ptr;
        *ptr+=1;
    }
    if (**ptr == ' ') {
        *status = 0;
    } else if (**ptr == '\n') {
        *status = 1;
    } else {
        *status = 2;
    }

    return tok;
}

// int main() {
//     char *ptr = (char*) malloc(20);
//     strcpy(ptr, "   hello goodbye\n");
//     int status;
//     printf("get_token returned '%s'\n", get_token(&ptr, &status));
// }

int main(int argc, char **argv) {
  char *line = (char*) malloc(80);
  char *baseline = line;
  size_t size = 80;
  int ret;  
  printf("Enter a line of input\n");
  if ((ret = getline(&line, &size, stdin)) < 0) {
    perror("getline");
    return -1;
  } 
  /* assert: input line stored in line[] */
  
  char *token; 
  int status;
  token = get_token(&line, &status);
  if (token == NULL)
    printf("get_token() returned NULL\n");
  else
    printf("get_token() returned '%s'\n", token);
    printf("status %d.  line[] now contains '%s'\n", status, line);
  
  free(token);
  free(baseline);
  return 0;
}
