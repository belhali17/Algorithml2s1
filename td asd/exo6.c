#include <stdio.h>

// Function to calculate Euler's Totient for N
int euler_totient(int N) {
    int result = N;  // Start with the value of N

    // Find the prime factors of N
    for (int p = 2; p * p <= N; p++) {
        // If p is a prime factor of N
        if (N % p == 0) {
            // Remove all factors of p from N
            while (N % p == 0) {
                N /= p;
            }
            // Apply the formula: result = result * (1 - 1/p)
            result -= result / p;
        }
    }

    // If there is a prime factor greater than sqrt(N)
    if (N > 1) {
        result -= result / N;
    }

    return result;
}

int main() {
    int N;

    printf("Enter an integer N: ");
    scanf("%d", &N);

    int phi = euler_totient(N);

    printf("The number of integers coprime with %d is: %d\n", N, phi);

    return 0;
}
