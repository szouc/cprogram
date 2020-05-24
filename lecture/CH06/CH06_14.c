
#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[5] = "AB";
    char b[5] = "AA";
    if(strcmp(a, b) > 0) 
        puts("a bigger than b.");
    strcpy(a, b);
    puts(a);
    return 0;
}
