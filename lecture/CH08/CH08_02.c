#include <stdio.h>

struct Student
{
    char name[10];
    char class[10];
    double math_score;
    double eng_score;
};

int main(void)
{
    char word[10];
    FILE *fp = fopen("score.txt", "r");
    while (fscanf(fp, "%s", word) == 1)
        fprintf(stdout, "%s\n", word);
    fclose(fp);
    return 0;
}