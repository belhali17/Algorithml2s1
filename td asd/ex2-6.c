#include <stdio.h>

// Function to compute the sum of the first N terms of the harmonic series
double harmonic_sum(int N) {
    if (N <= 0) {
        return 0; // Invalid input, return 0
    }

    double sum = 0.0;

    // Sum the reciprocals of the first N numbers
    for (int i = 1; i <= N; i++) {
        sum += 1.0 / i;
    }

    return sum;
}

int main() {
    int N;

    // Input the number of terms
    printf("Enter the number of terms (N): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Number of terms (N) must be greater than 0.\n");
        return 1;
    }

    // Compute the harmonic sum
    double result = harmonic_sum(N);
    printf("The sum of the first %d terms of the harmonic series is: %.6f\n", N, result);

    return 0;
}
