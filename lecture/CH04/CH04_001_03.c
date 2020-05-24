
#include <stdio.h>
#define INT_POINTER unsigned int *

int main(void)
{
    INT_POINTER a, b, c;
    b = 10;
    c = 20;
    a = &b;
    printf("a = %u\nb = %u\nc = %u\n", a, b, c);
    return 0;
}