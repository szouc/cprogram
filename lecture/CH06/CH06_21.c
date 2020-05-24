
#include <stdio.h>
#include <stdlib.h> // 包含管理堆的函数

int main(void)
{
    int *p = (int *)malloc(sizeof(int));
    *p = 5;
    printf("*p is %d\n", *p);
    free(p);

    return 0;
}