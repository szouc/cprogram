
#include <stdio.h>

typedef int (*FUNC_POINTER)(int, int);
int bigger(int, int);

int main(void) {
    int result;
    FUNC_POINTER p;
    p = &bigger;
    result = (******p)(5, 12);
    printf("bigger num is %d\n", result);
    return 0;
}

int bigger(int x, int y) {
    return x > y ? x : y;
}