
// This code is buggy.

#include <stdio.h>

int main(void)
{
    int a[5] = {5, 7, 1, 9, 6};
    int b[5];
    int *pa, *pb;
    int i;
    pa = a;
    pb = b;
    for (i = 0; i < 5; i++)
        *b++ = *a++;   // 数组名是常量指针，不能作为左值使用。
    for (i = 0; i < 5; i++)
        *pb++ = *pa++;
    for (i = 0; i < 5; i++)
        printf("%d\n", b[i]);

    return 0;
}