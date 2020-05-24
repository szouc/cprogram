
#include <stdio.h>
int n = 5;
int main(void)
{
    printf("out_main_n = %d\n", n);
    int n = 4;
    printf("in_main_n = %d\n", n);
    for(int n =0; n < 3; n++)
    {
        printf("for_n = %d\n", n);
        int n = 2;
        n++;
        printf("in_for_n = %d\n", n);
    }
}