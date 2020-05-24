
#include <stdio.h>
#define SIZE 5
int main(void)
{
    char * point_arr[SIZE] =
        {
            "Clang",
            "Python",
            "Java",
            "C++",
            "Golang"};
    int i;
    for (i = 0; i < SIZE; i++)
        printf("point_arr[%d] : %s\n", i, point_arr[i]);
    return 0;
}
