
#include <stdio.h>

int main(void)
{
    int a;
    a = 4;
    int b;
    b = 3;
    printf("a = %d, b = %d\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
