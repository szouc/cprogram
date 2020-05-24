#include <stdio.h>

int main(void)
{
    int i, j;
    char ch;
    ch = 'A';

    i = 0;
    while(i < 6)
    {
        j = 0;
        while(j <= i)
        {
            printf("%c", ch++);
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}