
#include <stdio.h>
int main(void)
{
    int num = 0;
    printf("Guess a number.\n");
    for (;num != 4;)
        scanf("%d", &num);
    printf("You win.\n");

    return 0;
}