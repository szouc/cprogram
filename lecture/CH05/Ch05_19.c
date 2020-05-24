
#include <stdio.h>
void print_count();
int main(void)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        print_count();
    }
}
void print_count()
{
    static int count = 0;
    printf("count is %d\n", count);
    count++;
}