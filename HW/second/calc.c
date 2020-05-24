#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, result;
    char op;
    int flag = 1;
    printf("Enter a expression: ");
    scanf("%lf%c%lf", &a, &op, &b);
    if (op == '+')
    {
        result = a + b;
    }
    else if (op == '-')
    {
        result = a - b;
    }
    else if (op == '*')
    {
        result = a * b;
    }
    else if (op == '/')
    {
        result = a / b;
    }
    else if (op == '^')
    {
        result = pow(a, b);
    }
    else
    {
        flag = 0;
    }
    if (flag)
        printf("result = %f", result);
    else
        printf("Error data\n");
    return 0;
}