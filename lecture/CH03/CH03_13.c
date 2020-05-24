
#include <stdio.h>

int main(void)
{
    int a, b, c, d;
    d = (a = 1, b = a + 1, c = b + 1);
    printf("a = %d,b = %d,c = %d,d = %d\n", a, b, c, d);

    d = (a - b) > 0 ? (a = 10) : (b = 20);
    printf("a = %d,b = %d,c = %d,d = %d\n", a, b, c, d);

    return 0;
}