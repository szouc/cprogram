#include <stdio.h>

int main(void)
{
    int result1, result2;
    result1 = 10 + 9 * ((8 +7) % 6) + 5 * 4 % 3 * 2 + 1;
    printf("result1 is %d\n", result1);
    result2 = 2 + 2 * (2 * 2 - 2) % 2 / 3;
    printf("result2 is %d\n", result2);

    return 0;
}