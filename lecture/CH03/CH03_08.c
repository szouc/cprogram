
#include <stdio.h>
int main(void)
{
    int m, n, sum = 0;

    printf("Plz input m & n: \n");
    scanf("%d %d", &m, &n);
    while ((sum += m, m += 1) <= n)
        ;
    printf("sum = %d\n", sum);
    return (0);
}