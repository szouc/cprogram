#include <stddef.h>
#include <stdio.h>

size_t strlen(const char *string)
{
    size_t length;
    for (length = 0; *string++ != '\0';)
        length += 1;
    return length;
}

int main(void)
{
    char p[] = "C language"; // const 是类型修饰符，修饰的实体不能修改
    printf("length of p is %zd\n", strlen(p));
    printf("p : %s\n", p);

    return 0;
}
