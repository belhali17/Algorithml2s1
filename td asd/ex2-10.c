#include <stdio.h>
#include <math.h>

// Function to compute the sum of the first N terms of an arithmetic-geometric series
double arithmetic_geometric_sum(double a, double d, double r, int N) {
    double sum = 0.0;

    // Loop through the first N terms and compute the sum
    for (int n = 1; n <= N; n++) {
        // T_n = (a + (n - 1) * d) * r^(n - 1)
        double term = (a + (n - 1) * d) * pow(r, n - 1);
        sum += term;
    }

    return sum;
}

int main() {
    double a, d, r;
    int N;

    // Input the parameters: first term a, common difference d, common ratio r, and number of terms N
    printf("Enter the first term a: ");
    scanf("%lf", &a);

    printf("Enter the common difference d: ");
    scanf("%lf", &d);

    printf("Enter the common ratio r: ");
    scanf("%lf", &r);

    printf("Enter the number of terms N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("N must be a positive integer.\n");
        return 1;
    }

    // Compute the sum of the arithmetic-geometric series
    double result = arithmetic_geometric_sum(a, d, r, N);
    printf("The sum of the first %d terms of the arithmetic-geometric series is: %.6f\n", N, result);

    return 0;
}
