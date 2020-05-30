#include <stdio.h>

int main(void)
{
    void plusone(int arr[][3], int n);
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    plusone(a, 2);  // int (*)[3]
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\n", a[i][j]);
        }
    }
    return 0;
}

void plusone(int arr[][3], int n) // int (*)[3]
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j]++;
        }
    }
}