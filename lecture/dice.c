#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void dice(void);
int main(void)
{
    int i = 10;
    while (i--)
    {
        dice();
        sleep(1);
    }
    return 0;
}

void dice(void)
{
    int num;
    srand((int)time(NULL));
    num = rand() % 6 + 1;
    printf("num is %d\n", num);
}