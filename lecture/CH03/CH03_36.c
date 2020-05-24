
#include <stdio.h>

int main(void)
{
    char ch;
    puts("Input \"hello world!\":");
    for (int count = 0; count < 10 ; count++)
    {
        ch = getchar();
        if (ch == ' ')
        {
            continue;
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}