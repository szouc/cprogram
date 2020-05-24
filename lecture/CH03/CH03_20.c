
#include <stdio.h>
int main(void)
{
    int index = 3; 
    while (index++ < 5)
        printf("index = %d\n", index);
    printf("The loop has finished.\n");
    return 0;
}