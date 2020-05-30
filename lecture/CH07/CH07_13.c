
#include <stdio.h>
union MixValue{
    int digit;
    double bignum;
    char letter;
};
int main(void) {
    union MixValue val;
    val.digit = 65;
    printf("%d\n", val.digit);
    printf("%f\n", val.bignum);
    printf("%c\n", val.letter);
    return 0;
}