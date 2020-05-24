
#include <stdio.h>
int main(void)
{
    int sum = 0;
    int i;
    printf("Plz input a num: \n");
    scanf("%d", &i);
    while (i <= 10)
    {
        sum += i;
        i++;
    }
    printf("sum = %d\n", sum);
    return 0;
}