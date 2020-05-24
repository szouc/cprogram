
#include <stdio.h>
int main(void)
{
    int sum = 0;
    int i;
    printf("Plz input a num: \n");
    scanf("%d", &i);
    do
    {
        sum += i;
        i++;
    } while (i <= 10);  // 注意分号
    printf("sum = %d\n", sum);
    return 0;
}