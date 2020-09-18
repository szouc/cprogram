
#include <stdio.h>
#define SIZE 5
int main(void)
{
    char * point_arr[SIZE] =
        {
            "Clang",  // point_arr[0] = "Clang";
            "Python",
            "Java",
            "C++",
            "Golang"};
    char *q = point_arr;
    int i;
    for (i = 0; i < SIZE; i++)
        printf("point_arr[%d] : %s\n", i, q[i]);
    return 0;
}
