#include <stdio.h>

int main(void)
{
    int i = 1;
    int sum = 0;
    int count = 0;
    do
    {
        sum = sum + i;
        i++;
        count++;
    } while(i <= 100);
    printf("sum = %d\n", sum);
    printf("count = %d\n", count);
    return 0;
}