
#include <stdio.h>

double rate = 0.1;
double sum_of_square_with_rate(double, double);
int main(void)
{
    double a = 3.0, b = 4.0;
    double result;
    int count = 1;
    while(count < 20)
    {
        result = sum_of_square_with_rate(a, b);
        printf("%d: result = %f\n", count, result);
        count++;
        rate = count < 10 ? rate : (rate + 0.1);
    }
    return 0;
}
double sum_of_square_with_rate(double x, double y)
{
    return x * x + y * y * rate;
}