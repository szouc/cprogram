#include <stdio.h>

int i =0;

int main(void)
{
    int f(int); // 函数原型
    printf("first is %d\n", f(1, 2));
    printf("second is %d\n", f(1));
    printf("third is %d\n", f(1));
    return 0;
}

int f(int n, int m)
{
    i++;
    return n + i;
}