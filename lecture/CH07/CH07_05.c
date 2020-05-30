
#include <stdio.h>
struct Record
{
    char name[20];
    float score;
};
int main(void)
{
    char status(struct Record);
    struct Record tom = {"Tom", 77.0};
    printf("Status of %s is %c\n", tom.name, status(tom));
    return 0;
}
char status(struct Record r)
{
    return r.score >= 60.0 ? 'Y' : 'N';
}