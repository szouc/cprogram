#include <stdio.h>

struct S1
{
    int x;
    int y;
} t1;

struct S2
{
    int x;
    int y;
};

// struct S1 t1 = {0, 0};
struct S1 t3 = {5, 7};
struct S2 t2 = {2, 3};
// t1 = t2;

int main(void)
{
    t1 = t3;
    printf("t1.x is %d\n", t1.x);
    return 0;
}