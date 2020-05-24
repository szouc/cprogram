#include <stdio.h>

int main(void)
{
    int sum(int, int);
    int (*psum)(int, int);
    psum = sum;
    int result;
    result = psum(3, 5);
    printf("result is %d\n", result);
    return 0;
}

int sum(int a, int b)
{
    return a + b;
}