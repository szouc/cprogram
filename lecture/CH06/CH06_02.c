
#include <stdio.h>

int main(void)
{
    // int m[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    int m[2][5] = {1, 2, 3, 5, 6, 4, 7, 8, 9, 10};
    int *p;
    p = &m[0][4];
    printf("*p = %d\n", *p);
    printf("m[0][4] = %d\n", m[0][4]);

    printf("*(p+1) = %d\n", *(p + 1));
    printf("m[1][0] = %d\n", m[1][0]);
    printf("*(p+2) = %d\n", *(p + 2));
    printf("m[1][1] = %d\n", m[1][1]);
}