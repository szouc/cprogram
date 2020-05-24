
#include <stdio.h>
int main(void)
{
    char ch;
    for (ch = 'A'; ch <= 'Z'; ch++)
        printf("%c is %#x.\n", ch, ch);

    return 0;
}