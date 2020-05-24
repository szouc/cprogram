
#include <stdio.h>
int fact(int, int *);
int main(void)
{
    int num, result;
    result = 1;
    int *presult = &result;
    puts("Please input a num: ");
    scanf("%d", &num);
    fact(num, presult);
    printf("fact of %d is %d\n", num, *presult);
    return 0;
}
int fact(int n, int *result)
{
    if (n == 0) // if(!n)
        return 1;
    else
    {
        *result *= n;
        return fact(n - 1, result);
    }
}