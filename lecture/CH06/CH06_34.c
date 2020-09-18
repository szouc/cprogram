#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str = "abc\\\\def";
    printf("%s\n", str);
    printf("length is %zd\n", strlen(str));
    int a = 5;
    printf("%d\n", (int)pow(10, 2));
    return 0;
}