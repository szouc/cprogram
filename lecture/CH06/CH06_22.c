
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *src = "Hello C language.";
    printf("src at %p: %s\n", src, src);
    char *dest = (char *)malloc(strlen(src) + 1);
    if(dest == NULL)
        exit(EXIT_FAILURE);
    strcpy(dest, src);
    printf("dest at %p: %s\n", dest, dest);
    char *inc_dest = (char*)realloc(dest, strlen(src) * 2);
    if(inc_dest == NULL){
        free(dest);
        exit(EXIT_FAILURE);
    }
    printf("inc_dest at %p: %s\n", inc_dest, inc_dest);
    free(inc_dest);
    return 0;
}
