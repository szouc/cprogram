
#include <stdio.h>
int main(void)
{
    int sum = 0;
    int i = 1;
    int count = 0;
    while (i <= 100)
    {
        sum += i;
        i++;
        count++;
    }
    printf("sum = %d\n", sum);
    printf("count = %d\n", count);
    return 0;
}