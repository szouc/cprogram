
#include <stdio.h>
#define SIZE 100

int main(void)
{
    int list[SIZE] = {9, 24, 79, 32, 12, 45, 89, 56};
    int *sqlist = list;
    int index, num, length = 8, i = 0;
    int *first, *last;
    puts("Plz input an index of position to delete(1-8):");
    scanf("%d", &index);
    if (index >= 1 && index <= 8) {
        first = &list[index - 1];
        last = &list[length - 1];
        num = *first;
        for (++first; first <= last; first++)
            *(first - 1) = *first;
        length--;
    }
    else
        printf("Index Error!");
    for (i = 0; i < length; i++)
        printf("%5d", list[i]);

    return 0;
}