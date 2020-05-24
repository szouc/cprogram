#include <stddef.h>
#include <stdio.h>

size_t strlen(const char *string)
{
    unsigned long length;
    for (length = 0; *string++ != '\0';)
        length += 1;
    return length;
}
int main(void)
{
    const char *p = "C language"; // const 是类型修饰符，修饰的实体不能修改
    printf("p : %s\n", p);
    printf("length of p is %zd\n", strlen(p));

    return 0;
}
