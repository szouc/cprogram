#include <stdio.h>

int main(void)
{
    int year, month, day;
    int feb_day = 28;
    printf("Input a date like yyyy-mm-dd:");
    scanf("%d-%d-%d", &year, &month, &day);
    if((!(year % 4) && (year % 100 != 0)) || (!(year % 400)))
        feb_day = 29;
    int sum = day;
    int months[12] = {31, feb_day, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 1; i < month; i++)
    {
        sum += months[i - 1];
    }
    switch(month)
    {
        case 12: sum += 30;
        case 11: sum += 31;
        case 10: sum += 30;
        case 9: sum += 31;
        case 8: sum += 31;
        case 7: sum += 30;
        case 6: sum += 31;
        case 5: sum += 30;
        case 4: sum += 31;
        case 3: sum += feb_day;
        case 2: sum += 31;
    }

    return 0;
}