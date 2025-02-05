#include <stdio.h>

// Function to compute the factorial of a number n
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i; // Multiply result by i
    }
    return result;
}

// Function to compute the sum of the factorials of the first N natural numbers
long long sum_of_factorials(int N) {
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += factorial(i); // Add the factorial of i to the sum
    }
    return sum;
}

int main() {
    int N;

    // Input the number of terms
    printf("Enter the number of terms (N): ");
    scanf("%d", &N);

    if (N < 1) {
        printf("N must be a positive integer.\n");
        return 1;
    }

    // Compute the sum of factorials
    long long result = sum_of_factorials(N);
    printf("The sum of the factorials of the first %d natural numbers is: %lld\n", N, result);

    return 0;
}
