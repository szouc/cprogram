
#include <stdio.h>

int main(void)
{
    char ch;
    while ((ch = getchar()) != 'q')
    {
        if (ch != 'g')
            printf("%c", ++ch);
        else
            printf("%c", ch);
    }

    return 0;
}