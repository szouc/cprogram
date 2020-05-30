#include <stdio.h>

void eleplus(int[], int);

int main(void)
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    eleplus(a, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("a[%d] is %d\n", i, a[i]);
    }
    return 0;
}

void eleplus(int *arr, int n)  //  int arr[];
{
    int *p;
    p = arr;
    while (n--)
        (*p++)++;
}