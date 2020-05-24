#include <stdio.h>

int m = 5;  // definition declaration

int main(void)
{
    extern int m; // reference declaration
    m++;
    printf("m = %d\n", m);

    return 0;
}