#include <stdio.h>

void fplus(int (*)[], int);

int main(void)
{
    int a[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int(*q)[5] = a;
    int n = 10;
    fplus(q, n);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 5; j++)
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
    return 0;
}
void fplus(int (*e)[], int n)
{
    while (n--)
        (*((*e) + n))++;
}