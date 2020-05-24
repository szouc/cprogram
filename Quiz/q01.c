
#include <stdio.h>
int main(void)
{
    int num;
    for (num = 1; num <= 5; num++)
    {
        if (num % 2 == 0)
            putchar('$');
        else
            putchar('*');
        putchar('#');
        putchar('%');
    }
    return 0;
}