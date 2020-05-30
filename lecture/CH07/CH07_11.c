
#include <stdio.h>
struct Node{
    int num;
    struct Node *next;
};
int main(void) {
    int n;
    struct Node *head, *p, *q, a, b, c, d;
    head = p = &a;
    a.num = 10; a.next = &b;
    b.num = 11; b.next = &c;
    c.num = 12; c.next = &d;
    d.num = 13; d.next = NULL;
    puts("Input a num (1~3): ");
    scanf("%d", &n);
    while(p && (n-- - 1)) p = p->next;
    q = p->next;
    p->next = q->next;
    while(head) {
        printf("%d\n", head->num);
        head = head->next;
    } 
    printf("Delete %d\n", q->num);
    return 0;
}