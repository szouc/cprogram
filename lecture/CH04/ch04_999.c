#include <stdio.h>

int main(void)
{
    int a[7] = {0, 1, 2, 3, 4, 5, 6};
    int *p, i;
    p = a;
    printf("a is %p\n", a);
    printf("p is %p\n", p);
    printf("p + 2 is %p\n", p + 2);
    printf("p + 3 is %p\n", p + 3);
    // for (i = 0; i < 7; i++)
    // {
    //     printf("a[%d] is %d\n", i, *(p++));
    // }

    return 0;
}