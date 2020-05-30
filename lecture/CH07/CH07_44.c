#include <stdio.h>

struct Point{
    int x;
    int y;
};

int area(struct Point, struct Point);

int main(void)
{
    struct Point lt, rb; // lt = left top ; rb = right bottom
    lt.x = 0;
    lt.y = 10;
    rb.x = 8;
    rb.y = 0;

    printf("Area is %d\n", area(lt, rb));

    return 0;
}

int area(struct Point p1, struct Point p2)
{
    int result = 0;
    result = (p2.x - p1.x) * (p1.y - p2.y);
    return result;
}