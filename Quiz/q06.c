#include <stdio.h>

int main(void)
{
    double n1, n2;
    double harmean(double, double);
    printf("Enter two double number:");
    scanf("%lf%lf", &n1, &n2);
    printf("%f\n", harmean(n1, n2));
    return 0;
}
double harmean(double x, double y)
{
    return 2 / (1 / x + 1 / y);
}