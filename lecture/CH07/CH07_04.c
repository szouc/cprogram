
#include <stdio.h>
struct Record {
    int id;
    char name[20];
    float score;
};
int main(void) {
    float aver(struct Record [], int);
    struct Record records[5] = {{1, "Mary", 80.5},
                                {2, "Oscar", 65.0},
                                {3, "Lucy", 78.5},
                                {4, "Harry", 100.0},
                                {5, "Woody", 90.5}};
    printf("Aver of score is %f\n", aver(records, 5));
    return 0;
}
float aver(struct Record r[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += r[i].score;
    }
    return sum / n;
}