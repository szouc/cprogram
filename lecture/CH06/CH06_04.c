
#include <stdio.h>
#define ROW 2
#define COL 3

int main(void)
{
    void copy_2D_array(int (*)[3], int[][3], int, int);
    int i, j;
    int a[ROW][COL] = {1, 2, 3, 4, 5, 6};
    int b[ROW][COL];
    int(*p)[COL] = b;
    copy_2D_array(a, b, ROW, COL);
    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            printf("Row %d, Col %d is %d\n", i, j, *(*(p + i) + j));
}
void copy_2D_array(int src[][3], int (*dest)[3], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            dest[i][j] = src[i][j];
}