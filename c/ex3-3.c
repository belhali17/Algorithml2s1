#include <stdio.h>
 int main() {
     int arr[5], sum = 0;
      float avg;
       printf("Enter 5 integers: ");
        for (int i = 0; i < 5; i++)
        {
             scanf("%d", &arr[i]);
             }
              for (int i = 0; i < 5; i++)
              {
                sum += arr[i];
                 }
                  avg = sum / 5.0;
                   printf("Sum: %d, Average: %.2f\n", sum, avg);
                    return 0;
                     }
