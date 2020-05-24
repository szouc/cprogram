
#include <stdio.h>

int main(void)
{
    char ch;
    printf("Input \"hello\":\n");
    while ((ch = getchar()) != EOF)
    {
        if (ch == 'l')
            break;
        printf("%c", ch);
    }
    printf("\n");

    return 0;
}