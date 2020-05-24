
#include <stdio.h>

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int i, arr_size;
    int *p;
    p = a;  // 数组名隐式转换成指向第一个元素的指针
    // 作为 sizeof 操作数，数组名不隐式转换
    arr_size = sizeof(a) / sizeof(int);

    // 数组下标返回变量，是左值
    for (i = 0; i < arr_size; i++)
    {
        printf("a[%d] is %-3d", i, a[i]++);
    }
    putchar('\n');
    // 指针访问数组元素
    for (i = 0; i < arr_size; i++)
    {
        printf("a[%d] is %-3d", i, *p++); // 换成 *a++ 会出错
    }
    putchar('\n');

    return 0;
}