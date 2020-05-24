#include <stdio.h>

int main(void)
{
    int a = 1;
    int c[2][2] = {1, 2, 3, 4};
    int (*d)[2];
    d = &c[0];
    int *b;
    b = &a;
    return 0;
}