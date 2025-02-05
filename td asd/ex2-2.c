#include <stdio.h>
#include <math.h>

// Function to compute the sum of the first N terms of a geometric series
double geometric_series_sum(double a, double r, int N) {
    if (N <= 0) {
        return 0; // No terms to sum
    }

    if (r == 1) {
        // Special case: when r = 1, all terms are equal to a
        return N * a;
    } else {
        // General case: use the geometric series formula
        return a * (1 - pow(r, N)) / (1 - r);
    }
}

int main() {
    double a, r;
    int N;

    // Input first term (a), common ratio (r), and number of terms (N)
    printf("Enter the first term (a): ");
    scanf("%lf", &a);
    printf("Enter the common ratio (r): ");
    scanf("%lf", &r);
    printf("Enter the number of terms (N): ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Number of terms (N) must be non-negative.\n");
        return 1;
    }

    // Compute the sum of the geometric series
    double result = geometric_series_sum(a, r, N);
    printf("The sum of the first %d terms of the geometric series is: %.6f\n", N, result);

    return 0;
}
