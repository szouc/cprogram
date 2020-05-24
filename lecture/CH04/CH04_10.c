
#include <stdio.h>

int main(void)
{
    int a[5] = {5, 7, 1, 9, 6};
    int *pa = a;
    int (*ap)[5] = &a;
    // pa = ap;
    printf("Address of the first element is %p\n", a);
    printf("Address of the first element is %p\n", pa);
    printf("Address of the array is %p\n", &a);
    printf("Address of the array is %p\n", ap);
    printf("Value of the first element is %d\n", *a);

    return 0;
}