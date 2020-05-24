#include <stdio.h>
#include <string.h>

void *uSearch(void *, void *, int, int, int (*cmp)(void *, void *));
int StrCmp(void *, void *);

int main(void)
{
    char *content[5] = {"Bb", "Em", "F#", "Gb", "Am"};
    char *pattern = "Gb";
    char **result;
    result = uSearch(&pattern, content, 5, sizeof(char *), StrCmp);
    if (result == NULL)
        printf("sorry\n");
    else
        printf("%s\n", *result);
    return 0;
}

int StrCmp(void *vp1, void *vp2)
{
    char *pb = *(char **)vp1;
    char *pk = *(char **)vp2;
    return strcmp(pb, pk);
}

void *uSearch(void *key, void *base, int n, int elemSize, int (*cmp)(void *s1, void *s2))
{
    for (int i = 0; i < n; i++)
    {
        void *elemAddr = (char *)base + i * elemSize;
        if (cmp(elemAddr, key) == 0)
            return elemAddr;
    }
    return NULL;
}