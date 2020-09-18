#include <stdio.h>
#include <string.h>

void sort(char **, int);
int main(void)
{
    char *a[5] = {"ABCD", "AAAA", "BCDA", "ACDB", "BDAC"};
    sort(a, 5);
    for (int i = 0; i < 5; i++) {
        printf("%s\n", a[i]);
    }
}

void sort(char **pp, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (strcmp(pp[i], pp[j]) > 0) {
                char *temp;
                temp = pp[i];
                pp[i] = pp[j];
                pp[j] = temp;
            }
        }
    }
}
