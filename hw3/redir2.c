#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>

int main(int argc, char **argv, char **envp) {
  char *array = (char*) malloc(20); 
  printf("Enter File Name: ");
  scanf("%19s", array);
  //printf("%s\n", array);
  int ret, ret1, dup1, closereturn;

  if ((ret = open(array, O_RDONLY)) < 0) {
        perror("open() failed");
        return -1;
    }
  
  if ((closereturn = close(0)) < 0) {
        perror("close");
        return -1;
    }

  dup1 = dup(ret);

  if ((ret1 = execve("/bin/head", argv, envp)) < 0) {
    perror("execve");
    return -1;
  }

  return 0;
}