
#include <stdio.h>
typedef int *INT_POINTER;
int main(void)
{
    void exchange(int *, int *);
    int a = 3, b = 5;
    INT_POINTER p, q;
    p = &a;
    q = &b;
    printf("before: a = %d, b = %d\n", a, b);
    exchange(p, q);
    printf("after: a = %d, b = %d\n", a, b);
    return 0;
}
void exchange(int *m, int *n)
{
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}