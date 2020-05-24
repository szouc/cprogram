#include <stdio.h>

int main(void)
{
    int a;
    int i,b;
    b = 0;
    scanf("%d", &a);
    while(a!=0)
    {
        i = a % 10;
        a = a / 10;
        b = b + i;
    }
    b = b + a;
    printf("%d", b);

    return 0;
}