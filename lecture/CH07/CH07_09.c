
#include <stdio.h>
struct Node{
    int num;
    struct Node *next;
};
int main(void) {
    int m, n;
    struct Node *head, *p, a, b, c, d;
    head = p = &a;
    a.num = 10; a.next = &b;
    b.num = 11; b.next = &c;
    c.num = 12; c.next = &d;
    d.num = 13; d.next = NULL;
    puts("Input a num (0~3): ");
    scanf("%d", &n);
    m = n;
    while(p && m--)
        p = p->next;
    printf("Num of %d element is %d\n", n, p->num);
    return 0;
}