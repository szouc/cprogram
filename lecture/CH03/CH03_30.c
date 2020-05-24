
#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Plz input two numbers: \n");
    scanf("%d%d", &a, &b);
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    printf("%d %d\n", a, b);
    return 0;
}