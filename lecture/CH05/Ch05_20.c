
#include <stdio.h>

extern int n;             // n 在其他文件定义实体
int m = 5;                // 外部链接，本文件定义实体
static int q = 4;         // 内部链接，只在本文件内可见
extern int sum(int, int); // sum 函数定义在其他文件

int main(void)
{
    void print_star();
    int i; // 无链接
    print_star();
}
void print_star() // 外部链接，本文件定义实体
{
    printf("*********");
}