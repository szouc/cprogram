#include <stdio.h>

int main(void)
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

    unsigned long siz;

    siz = sizeof(*(a + 1));

    printf("%d\n", (*(a + 1))[1]);
    // a[1]  ===>  *(a + 1)
    // (*(a + 1))[1]  ===> *(*(a + 1)) + 1)

    printf("%zd\n", siz);

    return 0;
}