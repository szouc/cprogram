#include <stdio.h>
#define SIZE 3

int main(void)
{
    int i, j, a[SIZE];
    int flag = 0;
    int min_index = 0;
    printf("Input three numbers:\n");
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &a[i]);
        min_index = a[min_index] < a[i] ? min_index: i; 
    }
    for(i = a[min_index]; flag == 0; i--)
    {
        flag = 1;
        for(j = 0; j < SIZE; j++)
        {
            flag = flag && (a[j] % i == 0);
        }
    }
    printf("greatest common divisor=%d\n", i + 1);
    return 0;
}