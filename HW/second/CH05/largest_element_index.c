#include <stdio.h>
#define SIZE 10

int main(void)
{
    int i, a[SIZE];
    int max_index = 0;
    printf("Input ten numbers:\n");
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &a[i]);
        max_index = a[max_index] > a[i] ? max_index : i; 
    }
    printf("Index of largest number is %d\n", max_index);

    return 0;
}