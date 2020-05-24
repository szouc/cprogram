
#include <stdio.h>
int main(void)
{
    int sum = 0;
    int i = 1;
    int count = 0;
    do
    {
        sum += i;
        i++;
        count++;
    } while (i <= 100);  // 注意分号
    printf("sum = %d\n", sum);
    printf("count = %d\n", count);
    return 0;
}