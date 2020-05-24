
#include <stdio.h>
int fibs(int);
int main(void) {
    int num, result;
    puts("Please input a num: ");
    scanf("%d", &num);
    if (num == 1) result = 1;
    else if (num == 2) result = 1;
    else result = fibs(num);
    printf("%dth num of fibs is %d\n", num, result);
    return 0;
}
int fibs(int n) {
    if (n == 2) return 1;
    else if (n == 1) return 1;
    else return fibs(n - 1) + fibs(n - 2);
}