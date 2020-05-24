
#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f;
    a = 1; b = 2; c = 3; d = 4;

    e = a * b + c * d;
    printf("e = %d\n", e);

    e = a + b + c + d;
    printf("e = %d\n", e);

    f = 0;
    e = a - b || (f = c - d);
    printf("e = %d, f = %d\n", e, f);
    e = a - b && (f = c - d);
    printf("e = %d, f = %d\n", e, f);

    return 0;
}