#include <stdio.h>

int main(void)
{
    int a = -1, b = 2;
    for (;b > 1; a++)
    {
        printf("%d %d", ++a, --b);
    }
    printf(" %d %d\n", a, b);
    return 0;
}