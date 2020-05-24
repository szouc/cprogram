
#include <stdio.h>

int main(void)
{
    int age;
    puts("Plz input your age: ");
    scanf("%d", &age);
    if (age > 18)
        goto pass;
    else
        goto refuse;
pass:
    puts("Welcome to the Adult World!");
    goto conclusion;
refuse:
    puts("You\'re still a kid.");
conclusion:
    return 0;
}