#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct _func_para
{
    int32_t x;
    int32_t y;
    int32_t z;
    void (*toString)(struct _func_para *this )
};

struct _func_res
{
    bool isRun;
};



int main(void)
{

    return 0;
}