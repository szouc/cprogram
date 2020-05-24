#include <stdio.h>
#define SIZE 10
int main(void)
{
    char arr[SIZE] = "Clang";
    char *p = arr;
    char **q = &p;
    int i;
    for (i = 0; i < SIZE; i++)
        printf("*(p + [%d]) : %c\n", i, *(p + i));
    *(*q + 1) = 'L';
    for (i = 0; i < SIZE; i++)
        printf("*(*q + %d) : %c\n", i, *(*q + i));
    return 0;
}
