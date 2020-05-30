
#include <stdio.h>
struct Node{
    int num;
    struct Node *next;
};
int main(void) {
    int n;
    struct Node *head, *p, *s, a, b, c, d, e;
    head = p = &a;
    a.num = 10; a.next = &b;
    b.num = 11; b.next = &c;
    c.num = 12; c.next = &d;
    d.num = 13; d.next = NULL;
    e.num = 99; e.next = NULL; s = &e;
    puts("Input a num (0~3): ");
    scanf("%d", &n);
    while(p && n--) p = p->next;
    s->next = p->next; p->next = s;
    while(head) {
        printf("%d\n", head->num);
        head = head->next;
    } 
    return 0;
}