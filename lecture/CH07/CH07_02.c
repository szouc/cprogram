#include <stdio.h>

struct Student
{
    char sex;
    char name[20];
    char addr[30];
    int num;
    int age;
    float score;
};

int main(void)
{
    struct Student stu1;
    printf("size of Student is %zd\n", sizeof(struct Student));
    return 0;
}