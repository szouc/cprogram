
#include <stdio.h>
#define SIZE 20

int main(void)
{
    int i;
    int fibs[SIZE] = {1, 1};
    float ratio[SIZE - 1];
    for (i = 2; i < SIZE; i++)
    {
        fibs[i] = fibs[i - 2] + fibs[i - 1];
    }
    for (i = 0; i < SIZE - 1; i++)
    {
        ratio[i] = (float)fibs[i] / fibs[i + 1];
        if (i % 5 == 0)
        {
            printf("\n");
        }
        printf("%-12.6f", ratio[i]);
    }

    return 0;
}