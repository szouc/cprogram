#include <stdio.h>

int main(void)
{
    int a[5];
    int b[3] = {1, 2, 3};
    int(*c)[5];

    c = &b;

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *((*c) + i));
    }

    return 0;
}