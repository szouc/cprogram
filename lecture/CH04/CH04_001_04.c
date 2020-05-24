
#include <stdio.h>
typedef int * INT_POINTER; 

int main(void)
{
    int num = 10;
    INT_POINTER a, b, c;
    a = b = c = &num;
    printf("a = %p\nb = %p\nc = %p\n", a, b, c);
    return 0;
}