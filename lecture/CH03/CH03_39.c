
#include <stdio.h>

int main(void)
{
    char ch;
    int pos = 1;
    int pr_int = 0;
    puts("Please input a num:");
    while(ch = getchar(), ch <= '9' && ch >= '0')
    {
        pr_int += pos * (ch - '0');
        pos *= 10;
    }
    printf("%d\n", pr_int);
    return 0;
}