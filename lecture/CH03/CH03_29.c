
#include <stdio.h>
#include <math.h>

int main(void)
{
    int num;
    int flag = 1;
    printf("Plz input a num: \n");
    scanf("%d", &num);
    for (int i = 2; (i <= sqrt(num)) && flag; i++)
    {
        if (num % i == 0)
            flag = 0;
    }
    if (flag)
        printf("%d is a Prime.\n", num);
    else
        printf("%d is not a Prime.\n", num);

    return 0;
}