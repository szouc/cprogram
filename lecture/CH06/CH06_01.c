
#include <stdio.h>

int main(void)
{
    int a[][3] = {1, 2, 3, 4, 5, 6}; // 声明中的列常量不能省略
    int i, j, r, c;
    // int(*p)[3] = a;
    int (*p)[3]; // Array Pointer
    p = a;

    r = sizeof(a) / sizeof(a[0]);
    c = sizeof(a[0]) / sizeof(a[0][0]);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d %d %d\n", a[i][j], *(*(a + i) + j), *(a[i] + j));
            printf("%d %d %d\n", p[i][j], *(*(p + i) + j), *(p[i] + j));
        }
    }

    return 0;
}