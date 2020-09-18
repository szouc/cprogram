#include <stdio.h>
#include <math.h>

int main(void)
{
    int x, n;
    double e = 1.0;
    scanf("%d%d", &x, &n);
    double fac(int);
    for (int i = 1; i < n; i++)
    {
        e = e + pow(x, i) / fac(i);
    }
    printf("%.6f", e);
    return 0;
}

double fac(int n)
{
    double k = 1.0;
    while (n > 0)
    {
        k = k * n;
        n = n - 1;
    }
    return k;
}