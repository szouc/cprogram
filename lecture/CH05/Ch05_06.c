
#include <stdio.h>

int sum(int, int);
int square(int);

int main(void) {
    int a, b;
    int result;
    puts("Please input two integer: ");
    scanf("%d%d", &a, &b);
    result = sum(square(a), square(b));
    printf("result = %d\n", result);
}

int sum(int x, int y) {
    return x + y;
}
int square(int x) {
    return x * x;
}