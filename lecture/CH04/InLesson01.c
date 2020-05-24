#include <stdio.h>

typedef int * INT_POINT;

int main(void)
{
    int a, b, c;
    INT_POINT pa, pb, pc;
    a = 1;
    b = 2;
    c = 3;
    pa = &a;
    pb = &b;
    pc = &c;
    printf("a = %d\n", (*++pa)++);
    printf("b = %d\n", ++*pb);
    printf("c = %d\n", --*pc);

    return 0;
}