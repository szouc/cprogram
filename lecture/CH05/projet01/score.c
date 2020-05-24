#include <stdio.h>

int main(void)
{
    extern double rate; // reference 
    double score = 99.0;

    printf("Final score is %f\n", score * rate);

    return 0;
}