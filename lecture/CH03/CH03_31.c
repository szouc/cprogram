
#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Plz input two numbers: \n");
    scanf("%d%d", &a, &b);
    if (a > b)
    {
        printf("%d %d\n", b, a);
    }
    else
    {
        printf("%d %d\n", a, b);
    }

    return 0;
}