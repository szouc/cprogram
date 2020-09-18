#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("/home/szouc/abcdef.txt", "w");
    fputs("Hello World1\n", fp);
    fclose(fp);

    FILE *rp = fopen("example.txt", "r");
    char str[20];
    fgets(str, 20, rp);
    puts(str);
    fclose(rp);


    return 0;
}