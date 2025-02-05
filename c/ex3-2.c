#include <stdio.h>
int main()
{
     int arr[5], largest, smallest;
     printf("Enter 5 integers: ");
     for (int i = 0; i < 5; i++)
      {
         scanf("%d", &arr[i]);
          }
           largest = smallest = arr[0];
            for (int i = 1; i < 5; i++)
            {
                if (arr[i] > largest) largest = arr[i];
                { if (arr[i] < smallest) smallest = arr[i];
             } }
              printf("Largest: %d, Smallest: %d\n", largest, smallest);
              return 0;
               }

