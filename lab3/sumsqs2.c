#include <stdio.h>

int square(int x) {
  return x*x;
}

int main() {
  int n;
  int result = 0;
  int i;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  i = 0;
  while (i <= n) {
    result = result + square(i);
    i++;
  }

  printf("The sum of the first %d integers is %d.\n", n, result);
  return 0;
}
