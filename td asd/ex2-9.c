#include <stdio.h>

// Function to compute the factorial of a number
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to compute the sum of the first N terms of the exponential series
double exponential_sum(double x, int N) {
    double sum = 1.0;  // The first term is 1 (x^0 / 0!)

    // Compute each term in the series and add to the sum
    for (int i = 1; i <= N; i++) {
        sum += (pow(x, i) / factorial(i));  // x^i / i!
    }

    return sum;
}

int main() {
    double x;
    int N;

    // Input the real number x and the number of terms N
    printf("Enter the value of x (real number): ");
    scanf("%lf", &x);

    printf("Enter the number of terms N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("N must be a positive integer.\n");
        return 1;
    }

    // Compute the exponential sum
    double result = exponential_sum(x, N);
    printf("The sum of the first %d terms of the exponential series e^%.2f is: %.6f\n", N, x, result);

    return 0;
}
