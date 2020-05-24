
#include <stdio.h>

int main(void)
{
    unsigned int num;
    char *p;
    num = 0x41424344;
    p = &num;
    for (int i = 0; i < 4; i++)
    {
        printf("%c\n", *(p + i));
    }

    return 0;
}