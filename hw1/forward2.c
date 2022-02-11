#include <stdio.h>
#include <stdlib.h>  /* for exit() */

int main(int argc, char **argv)
{
  char **ptr = argv;  /* pointer to an element of argv[] */
  while (*ptr) {
    printf("%d: %s\n", ptr-argv, *ptr);
    ptr++;
  }

  exit(argc);  /* normal exit status would be 0 */
}
