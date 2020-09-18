#include <stdio.h>
#define SIZE 5

int main(void)
{
    char str_arr[SIZE][10] =
        {
            "Clang",
            "Python",
            "Java",
            "C++",
            "Golang"};
    char (*p)[10] = str_arr;
    int i;
    for (i = 0; i < SIZE; i++)
        printf("str_arr[%d] : %s\n", i, str_arr[i]); // *(str_arr + i)
    for (i = 0; i < SIZE; i++)
        printf("*(p + %d) : %s\n", i, *p++);
    return 0;
}
