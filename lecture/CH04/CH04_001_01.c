
#include <stdio.h>

int main(void)
{
    int a;
    float b;
    char ch;
    printf("&a = %#lx\n&b = %p\n&ch = %p\n", &a, &b, &ch);
    return 0;
}