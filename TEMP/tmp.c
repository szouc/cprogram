#include <stdio.h>

int main(void)
{
    int a, b, c, max;
    a = 10;
    b = 20;
    c = 30;
    a = b || --c < 30 ? 0 : 1;
    printf("a = %d,b = %d,c = %d\n", a, b, c);

    return(0);
}
