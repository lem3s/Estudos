#include <stdio.h>
#include <limits.h>

int main() {
  /* INT_MAX is the maximum representable integer. */
  int a = INT_MAX;
  printf("a = %d\n", a);
  printf("Adding 1 to a...\n");
  a = a + 2;
  printf("a = %d\n", a);
  return 0;
}
