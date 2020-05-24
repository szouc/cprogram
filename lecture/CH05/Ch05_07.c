
#include <stdio.h>

int sum(int, int);
int square(int);

int main(void) {
    int (*p)(int,int);
    int (*q)(int);
    p = sum;
    q = square;
    printf("3 + 5 = %d\n", p(3, 5));
    printf("3 * 3 = %d\n", q(3));
    printf("3 * 3 + 5 * 5 = %d\n", p(q(3), q(5)));
    return 0;
}

int sum(int x, int y) {
    return x + y;
}
int square(int x) {
    return x * x;
}