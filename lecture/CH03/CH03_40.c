#include <stdio.h>

int main(void)
{
    char ch;
    int words, chars;
    words = chars = 0;
    puts("Plz input a statement: ");
    while((ch = getchar()) != 'q')
    {
        switch(ch)
        {
            case '\n': lines++;
            case ' ': words++;
            default: chars++;
        }
    }
    printf("words_num = %d, chars_num = %d\n", words, chars);

    return 0;
}