
#include <stdio.h>

int main(void)
{
    char ch;
    int i;
    float f;

    i = ch = 'A';
    f = i;
    printf("ch = %c, i = %i, f = %2.2f\n", ch, i, f);

    ch = ch + 1;
    i = f + 2 * ch;  // C 采用截断法，即截断小数部分。
    f = 2.0 * ch + i;
    printf("ch = %c, i = %i, f = %2.2f\n", ch, i, f);

    return 0;
}