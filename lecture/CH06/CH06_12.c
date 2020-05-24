
#include <stdio.h>
int main(void)
{
    char name[6], job[6], class[6], lang[6];
    scanf("%s%s%s%s", name, job, class, lang);
    printf("%s\n", name);
    puts(job);
    fputs(class, stdout);
    fputs(lang, stdout);
    return 0;
}
