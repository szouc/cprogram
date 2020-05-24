
#include <stdio.h>

int sum_of_square(int, int);

int main(void)
{
    int a, b;
    int result;
    puts("Please input two integer: ");
    scanf("%d%d", &a, &b);
    result = sum_of_square(a, b);
    printf("result = %d\n", result);
}

int sum_of_square(int x, int y)
{
    return x * x + y * y;
}