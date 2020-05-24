#include <stdio.h>

int d = 4;
const int c = 3;
char * e = "hello";
int main(void)
{
    int a = 1;
    const int b = 2;
    char * f = "world";
    const char * g = "hi";

    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);
    printf("%p\n", &d);
    printf("%p\n", e);
    printf("%p\n", f);
    printf("%p\n", g);
    printf("%p\n", &"there");

    return 0;
}