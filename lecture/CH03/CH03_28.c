#include <stdio.h>
#define ROWS 6     // 显示行数
#define MAX_COL 6  // 最大列数
int main(void)
{
    int row;  // 当前操作的行号
    char ch;  // 显示的字符
    for (row = 0; row <= ROWS; row++)
    {
        for (ch = ('A' + row); ch <= ('A' + MAX_COL); ch++)
        {
            printf("%c", ch);
        }
        printf("\n"); 
    }
    return 0;
}