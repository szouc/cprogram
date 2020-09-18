
#include <stdio.h>

int main(void)
{
    const int a = 1;
    a = 3;
    printf("a = %d\n", a);
    // const int n = 1;
    // n = 2; // 错误： n 的类型是 const 限定版本

    // int x = 2;
    // const int *p = &x;
    // *p = 3; // 错误： 左值 *p 的类型是 const 限定版本

    // int y = 2;
    // int * const q = &y;
    // *q = 3; // 正确： const 限定的是指针类型 q
    // q = p;  // 错误： 指针 q 的类型是 const 限定版本

    // const int * const ptr;

    return 0;
}

void func(char * restrict string)
{

}
