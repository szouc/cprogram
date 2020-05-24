
#include <stdio.h>
#define SIZE 10
int main(void)
{
    int list[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, j, temp, is_change = 1;
    int count = 0;
    // printf("Plz input %d numbers:\n", SIZE);
    // for (i = 0; i < SIZE; i++)
    //     scanf("%d", &list[i]);
    // puts("The numbers in list are as follows:");
    // for (i = 0; i < SIZE; i++)
    //     printf("%5d", list[i]);
    // printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        for (j = 1; j < SIZE - i && is_change; j++)
        {
            is_change = 0;
            count++;
            if (list[j - 1] > list[j])
            {
                is_change = 1;
                temp = list[j - 1];
                list[j - 1] = list[j];
                list[j] = temp;
            }
        }
    }
    puts("The sorted list is:");
    for (i = 0; i < SIZE; i++)
        printf("%5d", list[i]);
    printf("\n");
    printf("count is %d\n", count);
    return 0;
}