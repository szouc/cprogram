#include <stdio.h>

int main(int argc, char *argv[])
{
    char *change(char **);
    for(int i = 0; i < argc; i++)
        printf("%s\n", argv[i]);
    char *str = "hello";
    char *another;
    another = change(&str);
    puts(str);
    puts(another);
}

char *change(char **s)
{
    char *p = "string";
    *s = p;
    return "another";
}