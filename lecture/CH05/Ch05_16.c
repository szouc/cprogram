
#include <stdio.h>
void say_hello(int n); // n：函数原型作用域
int max = 5;           // n: 文件作用域
int main(void)
{
    say_hello(10);
}
void say_hello(int n) // n: 块作用域
{
    for (int i = 0; i < n; i++) // i: （if）块作用域
    {
        if (i >= max)
            goto n; // n: 函数作用域
        printf("hello\n");
    }
n: // n: 函数作用域
    printf("Limit %d times.\n", max);
}