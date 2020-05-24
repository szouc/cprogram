
#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest_str[] = "C language"; 
    char src_str[] = "Ocean University of China";
    strcpy(dest_str, src_str);
    printf("%s\n", dest_str);

    return 0;
}
