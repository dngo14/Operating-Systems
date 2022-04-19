#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>  
#include <sys/types.h>

int main(int argc, char **argv, char **envp) {

//   int ret;

//   if ((ret = execve("/bin/ls", argv, envp)) < 0) {
//     perror("execve");
//     return -1;
//   }
  int i = 0;
  while (envp[i]) {
      printf("%s\n", envp[i]);
      i++;
  }
  return 0;
}