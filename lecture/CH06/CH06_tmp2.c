#include <ctype.h>
#include <stdio.h>

int my_isalnum(char *);
int main(void)
{
    char *str = "ab34";
    printf("%d\n", my_isalnum(str));
    return 0;
}

int my_isalnum(char *p)
{
    int flag = 1;
    while (*p != '\0')
    {
        if (!isalnum(*p))
        {
            flag = 0;
            break;
        }
        p++;
    }
    return flag;
}