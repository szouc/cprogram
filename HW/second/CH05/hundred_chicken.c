#include <stdio.h>

int main(void)
{
    int cock, hen, chick;
    for (cock = 0; cock <= 20; cock++)
    {
        for (hen = 0; hen <= 33; hen++)
        {
            chick = 100 - cock - hen;
            if ((cock * 5 + hen * 3 + chick / 3 == 100) && (chick % 3 == 0))
                printf("cock = %d, hen = %d, chick = %d\n", cock, hen, chick);
        }
    }

    return 0;
}