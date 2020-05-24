
#include <stdio.h>
int main(void) {
    void hanoi(int, char, char, char);
    int num;
    puts("Please input a num: ");
    scanf("%d", &num);
    hanoi(num, 'A', 'B', 'C');
    return 0;
}
void hanoi(int n, char start, char offset, char end) {
    void move(char, int, char);
    if (n == 1)
        move(start, n, end);
    else {
        hanoi(n - 1, start, end, offset);
        move(start, n, end);
        hanoi(n - 1, offset, start, end);
    }
}
void move(char from, int n, char to) {
    static int count = 0;
    printf("%d: move disk %d %c --> %c\n", ++count, n, from, to);
}