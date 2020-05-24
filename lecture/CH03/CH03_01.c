#include <stdio.h>

void bubble_sort(int[], int);

int main(void)
{
   int a[8] = { 6, 4, 3, 1, 8, 7, 2, 4 };

   bubble_sort(a, 8);
   for (int i = 0; i < 8; i++)
   {
      printf("%d\n", a[i]);
   }
   return(0);
}

void bubble_sort(int a[], int n)
{
   for (int i = n - 1, change = 1; i >= 1 && change; --i)
   {
      change = 0;
      for (int j = 0; j < i; ++j)
      {
         if (a[j] > a[j + 1])
         {
            int temp = a[j];
            a[j]     = a[j + 1];
            a[j + 1] = temp;
            change   = 1;
         }
      }
   }
}
