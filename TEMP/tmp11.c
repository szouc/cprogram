
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (++i < 3)
        printf("Hi! ");
    do
        printf("Bye! ");
    while (i++ < 6);

    return 0;
}