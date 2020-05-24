
// This code is buggy.

#include <stdio.h>

int main(void)
{
    int a[5] = {5, 7, 1, 9};  // 没有问题
    int b[5];

    b = a;  // 错误，不允许数组作为整体赋值
    b[5] = a[5]; // 错误，数组下标越界
    b[5] = {5, 7, 1, 9};  //错误，不是初始化，不起作用

    return 0;
}