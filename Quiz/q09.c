#include <stdio.h>

int main()
{
    int search(int, int *, int);
    int a[10] = {1, 4, 6, 7, 9, 12, 15, 28, 39, 47 };
    int t, r;
    puts("Input a number: ");
    scanf("%d", &t);
    r = search(t, a, 10);
    if (r != -1)
        printf("Index of %d at %d\n", t, r);
    printf("Not found!\n");
    return 0;
}

int search(int tar, int *arr, int n)
{
    if (arr[0] <= tar && arr[n - 1] >= tar)
    {
        int begin = 0;
        int end = n;
        int mid = (begin + end) / 2;
        while ( mid != end && arr[mid] != tar)
        {
            if ( tar < arr[mid])
                end = mid;
            else
                begin = mid + 1;
            mid = (begin + end) / 2;
        }
        if ( begin == end )
            return -1;
        else
            return mid;
    }
    else
    if( tar == arr[end])
    {
        return -1;
    }
    
}