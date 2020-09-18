#include <stdio.h>

void plus(int **, int, int);
int main(void)
{
    int **pp;
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *parr[3];
    for(int i = 0; i < 3; i++)
    {
        parr[i] = a[i];
    }
    pp = parr;
    plus(pp, 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\n", a[i][j]);
        }
    }
    return 0;
}

void plus(int **ptr, int m, int n)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ptr[i][j]++;
        }
    }
}