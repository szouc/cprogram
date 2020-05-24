
#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[50] = "Scarlett";
    char address[20] = "Qingdao";
    printf("length of address is %zd\n", strlen(address));
    strcat(name, " "); 
    puts(strcat(name, address)); 
    puts(address);
    return 0;
}
