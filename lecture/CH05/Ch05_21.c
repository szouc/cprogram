
#include <stdio.h>

int main(void)
{
    int n = 5, i = 0;
    scanf("%d", &n);
    int numbers[n];
    numbers[0] = 0xFF;
    printf("%d", numbers[0]);
}