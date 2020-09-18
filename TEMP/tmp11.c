
#include <stdio.h>

int main(void)
{
    int a[3][4] = {0, 1, 2};
    int **q;
    int *c[4]; 
    c[0] = a[0];
    q = a;
    printf("%d\n", a[0][2]);
    printf("%d\n", c[0][2]);
    printf("%d\n", *(*((int(*)[4])q+0))+2);
    printf("%f\n", 3);
}