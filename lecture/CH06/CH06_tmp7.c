#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        *(p + i) = i + 6;
    }
    int *q = (int *)realloc(p, 10 * sizeof(int));
    if (q != NULL)
    {
        for (int i = 5; i < 10; i++)
        {
            *(q + i) = i + 6;
        }

        for (int i = 0; i < 10; i++)
        {
            printf("%d\n", *(q + i));
        }
        free(q);
    }
    else
    {
        free(p);
    }
    return 0;
}
