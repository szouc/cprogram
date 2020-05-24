
#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[] = "C language";
    char *pnoname = "C language";
    char *pname = name;
    printf("name : %s\n", name);
    printf("length of name is %zd\n", strlen(name));
    printf("pnoname : %s\n", pnoname);
    printf("length of pnoname is %zd\n", strlen(pnoname));
    *pname = 'B';
    printf("name : %s\n", name);
    printf("pname : %s\n", pname);

    // *pnoname = 'B';
    // printf("pnoname : %s\n", pnoname);
    pnoname = pname;
    printf("pnoname : %s\n", pnoname);
    return 0;
}