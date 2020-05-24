#include <stdio.h>
#define DURATION_MINUTE 40
#define DURATION_HOUR 12
#define TIMEDIFF_HOUR 16

int main(void)
{
    int depart_day, depart_hour, depart_minute;
    int arrive_day, arrive_hour, arrive_minute;
    int carry_hour = 0, carry_day = 0;
    printf("LA departure day:");
    scanf("%d", &depart_day);
    printf("Departure time:\n");
    scanf("%d:%d", &depart_hour, &depart_minute);
    arrive_minute = (depart_minute + DURATION_MINUTE) % 60;
    carry_hour = (depart_minute + DURATION_MINUTE) / 60;
    arrive_hour = (depart_hour + carry_hour + DURATION_HOUR + TIMEDIFF_HOUR) % 24;
    carry_day = (depart_hour + DURATION_HOUR + TIMEDIFF_HOUR) / 24;
    arrive_day = depart_day + carry_day;
    printf("%d day %02d:%02d takes off,%d day %02d:%02d arrived\n",
           depart_day, depart_hour, depart_minute, arrive_day, arrive_hour, arrive_minute);
    printf("Flight time is 12 hours and 40 minutes\n");
    return 0;
}