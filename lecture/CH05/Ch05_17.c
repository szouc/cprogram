
#include <stdio.h>
int m = 7;
int main(void)
{
    printf("m = %d\n", m);
    int n, m = 5;
    printf("m = %d\n", m);
    if (m > 3)
    {
        int m = 2;
        printf("m = %d\n", m);
        n = m;
    }
    else
    {
        int m = 3;
        printf("m = %d\n", m);
        n = m;
    }
    // printf("n = %d, m = %d\n", n, m);
}