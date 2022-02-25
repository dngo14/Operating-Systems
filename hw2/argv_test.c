#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>

int main(int argc, char **argv, char **envp) {
  char arg1[3] = {'l','s','\0'};
  char arg2[3] = {'-','l','\0'};
  char arg3[2] = "/";
  char **arr = (char**) malloc(sizeof(char*[4]));
  arr[0] = arg1;
  arr[1] = arg2;
  arr[2] = arg3;
  arr[3] = 0;
  


  int ret;

  if ((ret = execve("/bin/ls", arr, envp)) < 0) {
    perror("execve");
    return -1;
  }

  return 0;
}