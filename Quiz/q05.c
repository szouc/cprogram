#include <stdio.h>

void chline(char, int, int);
int main(void)
{
    char c;
    int i, j;
    printf("char:");
    scanf("%c", &c);
    printf("cols and rows:");
    scanf("%d%d", &i, &j);
    chline(c, i, j);
    return 0;
}
void chline(char ch, int cols, int rows)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%c", ch);
        printf("\n");
    }
}
