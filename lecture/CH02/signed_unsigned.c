
#include <stdio.h>

int main(void)
{
    int i = 2147483647;
    unsigned int j = 4294967295;

    // print i, i+1, i+2
    printf("signed: i = %d, i+1 = %d, i+2 = %d\n", i, i + 1, i + 2);
    printf("unsigned: i = %u, i+1 = %u, i+2 = %u\n", i, i + 1, i + 2);
    // print j, j+1, j+2
    printf("signed: j = %d, j+1 = %d, j+2 = %d\n", j, j + 1, j + 2);
    printf("unsigned: j = %u, j+1 = %u, j+2 = %u\n", j, j + 1, j + 2);

    return 0;
}