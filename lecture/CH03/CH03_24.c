
#include <stdio.h>
int main(void)
{
    int secs;
    for (secs = 10; secs > 0; secs--)
        printf("%d sections!\n", secs);
    printf("Ignition!\n");

    return 0;
}