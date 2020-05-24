
#include <stdio.h>
int main(void)
{
    int aver(int[], int);
    int average;
    int score[10] =
        {93, 95, 74, 60, 78, 100, 72, 68, 82, 84};
    average = aver(score, 10);
    printf("average = %d\n", average);
    return 0;
}
int aver(int arr[], int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}