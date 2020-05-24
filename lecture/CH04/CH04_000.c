
#include <stdio.h>

int main(void)
{
    int a = 1078523331;
    float b = 3.14;
    unsigned char *ca, *cb;
    ca = (unsigned char *)&a;
    cb = (unsigned char *)&b;
    // 呈现 a 在内存中的十六进制数值
    printf("hex_a = ");
    for (int i = 0; i < sizeof(int); i++)
        printf("%.2x", *(ca + i));
    printf("\n");
    // 呈现 b 在内存中的十六进制数值
    printf("hex_b = ");
    for (int i = 0; i < sizeof(float); i++)
        printf("%.2x", *(cb + i));
    printf("\n");
    return 0;
}