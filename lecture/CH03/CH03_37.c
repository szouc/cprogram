
#include <stdio.h>
int main(void) {
    char score, postfix;
    puts("Plz input the score: ");
    scanf("%c%c", &score, &postfix);
    switch (score) {
    case '5':
        switch (postfix) {
        case '+': puts("100"); break;
        case '\n': puts("90"); break;
        case '-': puts("85"); break;
        }
        break;
    case '4':
        switch (postfix) {
        case '+': puts("80"); break;
        case '\n': puts("75"); break;
        case '-': puts("70"); break;
        }
        break;
    case '3': puts("60"); break;
    case '2':
    case '1': puts("<60"); break;
    }
    return 0;
}