
#include <stdio.h>

typedef int (*FUNC_POINTER)(int);
int cube(int);
int square(int);
int calc(FUNC_POINTER, int);

int main(void) {
    int result;
    FUNC_POINTER p, q;
    p = cube;
    q = square;
    printf("square 3 is %d\n", calc(q, 3));
    printf("cube 3 is %d\n", calc(p, 3));
    return 0;
}

int cube(int x) {
    return x * x * x;
}
int square(int x) {
    return x * x;
}
int calc(FUNC_POINTER pf, int x)
{
    return pf(x);
}