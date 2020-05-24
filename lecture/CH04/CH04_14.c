
#include <stdio.h>
#define SIZE 100

int main(void)
{
    int list[SIZE];
    int *sqlist = list;
    int length = 0, i = 0;
    int num, is_found = 0;
    puts("Plz input some(<100) numbers(q to quit):");
    // scanf("%d", sqlist++);
    while (scanf("%d", sqlist++) == 1)
        length++;
    getchar();
    puts("Plz input a number to locate:");
    scanf("%d", &num);
    for (i = 0; i < length; i++) {
        if (num == list[i]) {
            printf("Index of %d is %d\n", num, i);
            is_found = 1;
            break;
        }
    }
    if(!is_found)
        puts("Sorry Not Found!");
    return 0;
}