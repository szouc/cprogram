
#include <stdio.h>

int main(void)
{
    unsigned int * a, b, c;
    int * p;

    b = 10;
    c = 20;
    a = &b;
    printf("a = %u\nb = %u\nc = %u\n", a, b, c);
    return 0;
}