
#include <stdio.h>
int main(void)
{
    int m, n, sum = 0;

    printf("Plz input m & n: \n");
    scanf("%d %d", &m, &n);
    if (m < n)
    {
        while (m <= n)
        {
            sum = sum + m;
            m = m + 1;
        }
        printf("sum = %d\n", sum);
    }
    else
    {
        printf("Wrong Input!!\n");
    }
    return (0);
}
