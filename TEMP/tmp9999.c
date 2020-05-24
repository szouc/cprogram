#include <stdio.h>

int main()
{
    int a, b, c;
    printf("LA departure day:");
    scanf("%d", &a);
    printf("Departure time:\n");
    scanf("%d:%d", &b, &c);
    printf("%d day %02d:%02d takes off,", a, b, c);

    b += 28;
    c += 40;
    while (c >= 60)
        c -= (b++, 60);
    while (b >= 24)
        b -= (a++, 24);
    printf("%d day %02d:%02d arrived\nFlight time is 12 hours and 40 minutes", a, b, c);
    return 0;
}