#include <stdio.h>

void swap(int ** a, int ** b)
{
    int * tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 3, 3, 4, 5};
    swap(&a, &b);
    printf("%d %d\n", a[0], a[1]);

    return 0;
}