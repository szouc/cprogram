
#include <stdio.h>

int main(void)
{
  int a[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24}, *q[4], k;
  for (k = 0; k < 4; k++)
    q[k] = &a[k * 3];

  printf("%d\n", q[3][1]);

  return 0;
}