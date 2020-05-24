
#include <stdio.h>

int count = 10;
void print_star(void);
int main(void)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        print_star();
        printf("count is %d\n", count);
    }
    return 0;
}

void print_star()
{
    count--;
    printf("*\n");
}