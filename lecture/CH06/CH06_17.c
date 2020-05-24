
#include <stdio.h>
#define SIZE 5
int main(void)
{
    char *point_arr[SIZE] =
        {
            "Clang",
            "Python",
            "Java",
            "C++",
            "Golang"};
    char **pp = point_arr;
    int i;
    for (i = 0; i < SIZE; i++)
        printf("point_arr[%d] : %s\n", i, point_arr[i]);
    for (i = 0; i < SIZE; i++)
        printf("*(pp + %d) : %s\n", i, *(pp + i));
    return 0;
}
