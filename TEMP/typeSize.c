#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("char is %zu\n", sizeof(char));
    printf("int is %zu\n", sizeof(int));
    printf("short int is %zu\n", sizeof(short int));
    printf("long int is %zu\n", sizeof(long int));
    printf("long long int is %zu\n", sizeof(long long int));
    printf("float is %zu\n", sizeof(float));
    printf("double is %zu\n", sizeof(double));
    printf("long double is %zu\n", sizeof(long double));
    printf("_Bool is %zu\n", sizeof(_Bool));       // C99 Keywords
    printf("_Complex is %zu\n", sizeof(_Complex double)); // C99 Keywords
    printf("int * is %zu\n", sizeof(int *));
    printf("char * is %zu\n", sizeof(char *));
    printf("literal string is %zu\n", sizeof("C language is Awesome!"));
    printf("\x6d\n");
    return 0;
}
