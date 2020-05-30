
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int num;
    struct Node *next;
};
int main(void) {
    struct Node *head, *p;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    for (int i = 0; i < 5; i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        puts("Input data: ");
        scanf("%d", &(p->num));
        p->next = head->next; head->next = p;
    }
    puts("LinkList: ");
    while(head->next) {
        head = head->next;
        printf("%4d", head->num);
    } 
    puts("\n");
    return 0;
}