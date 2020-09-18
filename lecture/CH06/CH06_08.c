
#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest_str[] = "C language";
    char ch = 'A';
    char src_str[] = "Ocean University of China";
    printf("%c\n", ch);
    strcpy(dest_str, src_str);
    printf("%s\n", dest_str);
    printf("%c\n", ch);

    return 0;
}
