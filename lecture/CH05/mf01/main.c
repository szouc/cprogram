#include <stdio.h>

// extern void print_start();

int main(void)
{
    extern void print_start(); // 块作用域的函数，只能使用 extern 存储类别符修饰
    void print_double_start();

    print_start();
    print_double_start();
    return 0;
}

void print_double_start()
{
    // print_start();
    // print_start();
}

// void print_start()
// {
//     printf("****inside****\n");
// }