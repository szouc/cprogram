
/*
if (expression)
    statement
if (expression)
    statement
else
    statement
*/

/*
if (expression)
{
    statement
    if (expression)
        statement
}
else
    statement
*/

#include <stdio.h>

int main(void)
{
    int age;
    printf("Plz input your age: \n");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("You can drive.\n");
        if (age >= 22)
            printf("You can marry.\n");
    }
    else
        printf("Sorry, you\'re a child.\n");

    return 0;
}