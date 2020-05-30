#include <stdio.h>

int main(void)
{
    int a[2][3];
    a[1][2] = 10;

    printf("a[1][2] = %d\n", a[1][2]);
    return 0;
}