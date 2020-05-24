
#include <stdio.h>

int main(void)
{
    int i;
    int (*a)[3];
    int b[3];
    a = &b;
    for (i = 0; i < 3; i++)
        b[i] = i;
    for (i = 0; i < 3; i++)
        (*a)[i]++; 
    for (i = 0; i < 3; i++)
        printf("b[%d] = %d\n", i, b[i]);
    return 0;
}