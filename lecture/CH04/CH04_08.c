
// This code is buggy.

#include <stdio.h>

int main(void)
{
    int a[5] = {5, 7, 1, 9, 6};
    int b[5];
    int i;
    for (i = 0; i <= 5; i++)
        b[i] = a[i];
    for (i = 0; i <= 5; i++)
        printf("%d\n", b[i]);

    return 0;
}