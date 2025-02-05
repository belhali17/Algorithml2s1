#include <stdio.h>

// Function to compute the sum of the squares of the first N natural numbers
long long sum_of_squares(int N) {
    if (N <= 0) {
        return 0; // No terms to sum
    }
    // Use the formula: S = N * (N + 1) * (2N + 1) / 6
    return (long long)N * (N + 1) * (2 * N + 1) / 6;
}

int main() {
    int N;

    // Input the number of terms
    printf("Enter the number of terms (N): ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Number of terms (N) must be non-negative.\n");
        return 1;
    }

    // Compute the sum of squares
    long long result = sum_of_squares(N);
    printf("The sum of the squares of the first %d natural numbers is: %lld\n", N, result);

    return 0;
}
