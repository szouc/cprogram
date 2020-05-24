
#include <stdio.h>

int main(void)
{
    int a = 1;
    int *b;
    b = &a;
    // *b 是左值，可以作为赋值运算符左操作数
    *b = 2;  
    printf("b = %p\n", b);
    printf("a = %d\n", a);
    printf("*b = %d\n", *b);

    return 0;
}