#include <stdio.h>

struct Record {
    int std_id;
    int team_id;
    char name[20];
    int lang_sc;
    int math_sc;
    int eng_sc;
    int phy_sc;
};

int main(void)
{
    int aver = 0;
    struct Record zq =
        {201070009, 1, "zhangqian", 118, 143, 132, 97};
    aver =
        (zq.lang_sc + zq.math_sc + zq.eng_sc + zq.phy_sc) / 4;
    printf("aver of zq is %d\n", aver);
    return 0;
}
