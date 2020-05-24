#include <stdio.h>

const char name[] = "Hello world";
int main(void)
{
    ((char*)name)[2] = '3';
    printf("%s\n", name);
    return 0;
}