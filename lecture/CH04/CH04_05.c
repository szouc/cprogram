
#include <stdio.h>
#define SIZE 10

int main(void)
{
    float score[SIZE];
    float sum, aver;
    int i;
    sum = 0;
    printf("Plz input %d scores:\n", SIZE);
    for(i = 0; i< SIZE; i++)
        scanf("%f", &score[i]);
    puts("The scores read in are as follows:");
    for(i = 0; i< SIZE; i++)
        printf("%6.1f", score[i]);
    printf("\n");
    for(i = 0; i< SIZE; i++)
        sum += score[i];
    aver = sum / SIZE;
    printf("Sum of score = %.2f, aver = %.2f\n", sum, aver);

    return 0;
}