
#include <stdio.h>
int fact(int);
int main(void)
{
    int num, result;
    puts("Please input a num: ");
    scanf("%d", &num);
    result = fact(num);
    printf("fact of %d is %d\n", num, result);
    return 0;
}
int fact(int n)
{
    if (n == 0) // if(!n)
        return 1;
    else
        return n * fact(n - 1);
}