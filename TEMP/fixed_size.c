#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int32_t i;
    uint64_t j;
    i = 1;
    j = 1;
    printf("i = %" PRId32 ", j = %" PRIu64 "\n", i, j);

    return 0;
}