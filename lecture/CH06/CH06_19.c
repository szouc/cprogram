#include <stdio.h>
#include <string.h>
#define SIZE 5
int main(void)
{
    char *point_arr[SIZE] =
        {"Clang", "Python", "Java", "C++", "Golang"};
    char **p = point_arr;
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = i; j < SIZE; j++)
        {
            if (strcmp(*(p + i), *(p + j)) > 0)
            {
                char *temp;
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }
    for (i = 0; i < SIZE; i++)
        printf("point_arr[%d] : %s\n", i, point_arr[i]);
    return 0;
}
