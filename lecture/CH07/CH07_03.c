
#include <math.h>
#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main(void)
{
    double dist, x_dist_square, y_dist_square;
    struct Point p1 = {5, 7};
    struct Point p2 = {2, 3};
    x_dist_square = pow(((double)p1.x - p2.x), 2.0);
    y_dist_square = pow(((double)p1.y - p2.y), 2.0);
    dist = sqrt(x_dist_square + y_dist_square);
    printf("Distance between p1 and p2 is %f\n", dist);

    return 0;
}