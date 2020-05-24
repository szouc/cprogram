
#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[] =
        {'C', ' ', 'l', 'a', 'n', 'g', 'u', 'a', 'g', 'e', '\0'};
    char b[] = "C language";
    printf("%s\n", a);
    printf("length of a is %zd\n", strlen(a));
    printf("%s\n", b);
    printf("length of b is %zd\n", strlen(b));
    return 0;
}