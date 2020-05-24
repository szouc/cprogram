#include <stdio.h>
#define SIZE 3

int main(void)
{
    int i, j, a[SIZE];
    int flag = 0;
    int *min_pointer;
    min_pointer = a;
    printf("Input three numbers:\n");
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &a[i]);
        min_pointer = *min_pointer < a[i] ? min_pointer : &a[i]; 
    }
    for(i = *min_pointer; flag == 0; i--)
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