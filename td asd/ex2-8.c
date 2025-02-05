#include <stdio.h>

// Function to compute the sum of the first N terms of an alternating series
int alternating_sum(int N) {
    int sum = 0;

    // Loop through the first N terms
    for (int i = 1; i <= N; i++) {
        // Add i if i is odd, subtract i if i is even
        if (i % 2 != 0) {
            sum += i;  // Odd index: add
        } else {
            sum -= i;  // Even index: subtract
        }
    }

    return sum;
}

int main() {
    int N;

    // Input the number of terms
    printf("Enter the number of terms (N): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("N must be a positive integer.\n");
        return 1;
    }

    // Compute the alternating sum
    int result = alternating_sum(N);
    printf("The sum of the first %d terms of the alternating series is: %d\n", N, result);

    return 0;
}
