
#include <stdio.h>
int main(void)
{
    int i, j;
    for(i = 1; i<= 9; i++)
    {
        for(j = 1; j<=9; j++)
        {
            printf("%d*%d=%-4d", i, j, i*j);
        }
        printf("\n");  // 每行 9 个式子
    }
    return 0;
}