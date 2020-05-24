
#include <stdio.h>

int main(void)
{
    int a = 1;
    int *b;
    b = &a;
    printf("b = %p\n", b);
    printf("*b = %d\n", *b);

    return 0;
}