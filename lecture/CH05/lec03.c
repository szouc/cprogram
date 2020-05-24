#include <stdio.h>

int main(void)
{
    int sum(int, int);
    int m = 3, n = 5;
    int result;
    result = sum(m, n);
    printf("result is %d\n", result);
    return 0;
}

int square(int a)
{
    return a * a;
}

int sum(int x, int y)
{
    return square(x) + square(y);
}