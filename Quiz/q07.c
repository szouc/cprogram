
#include <stdio.h>

int main(void)
{
    int a[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int *p[4];
    for (int j = 0; j < 4; j++)
        p[j] = a[j];
    printf("%d,%d,%d,%d\n", *p[1], (*p)[1], p[3][2], *(p[3] + 1));
}
