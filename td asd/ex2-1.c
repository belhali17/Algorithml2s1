#include <stdio.h>

// Function to compute the sum of the first N terms of an arithmetic series
long long arithmetic_series_sum(int a, int d, int N) {
    if (N <= 0) {
        return 0; // No terms to sum
    }
    // Use the formula: S_N = N/2 * (2a + (N - 1) * d)
    long long sum = (long long)N * (2 * a + (N - 1) * d) / 2;
    return sum;
}

int main() {
    int a, d, N;

    // Input first term (a), common difference (d), and number of terms (N)
    printf("Enter the first term (a): ");
    scanf("%d", &a);
    printf("Enter the common difference (d): ");
    scanf("%d", &d);
    printf("Enter the number of terms (N): ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Number of terms (N) must be non-negative.\n");
        return 1;
    }

    // Compute the sum of the series
    long long result = arithmetic_series_sum(a, d, N);
    printf("The sum of the first %d terms of the arithmetic series is: %lld\n", N, result);

    return 0;
}
