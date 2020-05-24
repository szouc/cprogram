
#include <stdio.h>

int func(int);
int main(void)
{
    int a[5] = {5, 7, 1, 9};  // 没有问题
    int b[5];
    int c[func(5)];
    int d['c'];
    int *p;

    p = c;
    for (int i =0; i < 5; i++)
    {
        *p++ = a[i];
    }
    
    for (int i =0; i < 5; i++)
    {
        printf("%d\n", c[i]);
    }

    return 0;
}

int func(int a)
{
    return a;
}