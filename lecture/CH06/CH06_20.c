#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _FlexibleArray
{
    int index;
    char data[0];
} FlexibleArray;

int main(void)
{
    FlexibleArray *p;
    unsigned long size = sizeof(FlexibleArray) + strlen("hello world!\n") + 1;
    p = (FlexibleArray *)malloc(size);
    assert(p != NULL);
    memcpy(p, "\x01\x00\x00\x00Hello world!\n", size);
    printf("%d\n", p->index);
    printf("%s\n", p->data);
    free((void *)p);
    return 0;
}