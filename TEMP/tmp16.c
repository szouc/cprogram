#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "\141";
    printf("%zd, %s\n", strlen(s), s);
    return 0;
}