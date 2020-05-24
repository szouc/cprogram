#include <stdio.h>

int main(void)
{
    int num;
    int result;
    int left;
    printf("Plz input num:\n");
    scanf("%d", &num);
    do
    {
        result = 0;
        while (num)
        {
            left = num % 10;
            num = num / 10;
            result = result + left;
        }
        num = result;
    } while (result >= 10);

    printf("result = %d\n", result);

    return 0;
}