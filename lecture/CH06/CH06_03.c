
#include <stdio.h>

unsigned int var_arr(int n)
{
    signed int va[n];
    return sizeof va;
}

int main(void)
{
    int n = 30;
    signed char c = 0;
    int var[n];
    size_t siz = sizeof 0;
    printf("siz = %zd\n", siz);
    siz = sizeof(c = 1);
    printf("siz = %zd\n", siz);
    printf("c = %d\n", c);
    siz = sizeof(int [30]);
    printf("siz = %zd\n", siz);
    siz = sizeof(int [n]);
    printf("siz = %zd\n", siz);
    siz = var_arr(n);
    printf("siz = %zd\n", siz);
}