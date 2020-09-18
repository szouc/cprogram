#include <stdio.h>

int main(void)
{
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int (*p)[3];
    p = &a[1];
    printf("%d\n", p[1][2]);

    return 0;
}