/* test program for mkdir() 
   2 command line arguments:  path and mode */

#include <stdio.h>
#include <stdlib.h>    /* for strtol() */
#include <sys/stat.h>  
#include <sys/types.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("%s:  expects 2 arguments, exiting\n", argv[0]);
    return -1;  
  }

  int ival = strtol(argv[2], NULL, 8);
  printf("int value of %s is 0%o\n", argv[2], ival);
  mode_t mode = ival;  

  int ret;
  if ((ret = mkdir(argv[1], mode)) < 0) {
    perror("mkdir() failed");
    return -1;  
  }

  printf("mkdir() returned %d\n", ret);

  return 0;
}
