
#include <stdio.h>

int main(void)
{
    int i;
    int *a[3];
    int b[3];
    for (i = 0; i < 3; i++)
        b[i] = i;
    for (i = 0; i < 3; i++)
        printf("b[%d] = %d\n", i, b[i]);
    for (i = 0; i < 3; i++)
        a[i] = &b[i];
    for (i = 0; i < 3; i++)
        *a[i] = *a[i] + i * 1;
    for (i = 0; i < 3; i++)
        printf("b[%d] = %d\n", i, b[i]);
    return 0;
}