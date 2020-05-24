#include <stdio.h>
#include <math.h>

int main(void)
{
    int num;
    printf("input num:");
    scanf("%d", &num);
    if(num < 2)
        printf("nearest prime is 2.\n");
    else if(num == 2)
        printf("nearest prime is 3.\n");
    else
    {
        int temp, i, num_origin;
        num_origin = num;
        for(temp = num + 1; ;num++)
        {
            // important
            int flag = 1;
            for(i = 2; i <= sqrt(temp); i++)
            {
                if( temp % i == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) break;
        }
        int temp2;
        num = num_origin;
        for(temp2 = num - 1; temp2 >= 2;num--)
        {
            // important
            int flag = 1;
            for(i = 2; i <= sqrt(temp); i++)
            {
                if( temp % i == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) break;
        }
        if(temp - num_origin  < num_origin - temp2)
            printf("nearest prime is %d\n", temp);
        else if(temp - num_origin == num_origin - temp2)
            printf("neast prime are %d and %d", temp, temp2);
        else
            printf("nearest prime is %d\n", temp2);
    }
    return 0;
}