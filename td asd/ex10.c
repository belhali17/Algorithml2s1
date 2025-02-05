#include <stdio.h>

// Function to compute GCD and modular inverse using the Extended Euclidean Algorithm
int extended_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

// Function to solve a system of simultaneous congruences
// using the Chinese Remainder Theorem
int solve_crt(int n[], int r[], int k) {
    // Compute the product of all moduli
    long long N = 1;
    for (int i = 0; i < k; i++) {
        N *= n[i];
    }

    long long result = 0;

    // Apply the CRT formula
    for (int i = 0; i < k; i++) {
        long long Ni = N / n[i]; // N_i = N / n[i]
        int x, y;
        // Compute the modular inverse of Ni modulo n[i]
        extended_gcd(Ni, n[i], &x, &y);
        int inverse = (x % n[i] + n[i]) % n[i];
        result += r[i] * Ni * inverse;
        result %= N;
    }

    return (result % N + N) % N; // Ensure the result is non-negative
}

int main() {
    int k;
    printf("Enter the number of congruences (k): ");
    scanf("%d", &k);

    int n[k], r[k];
    printf("Enter the moduli (n[i]) and remainders (r[i]):\n");
    for (int i = 0; i < k; i++) {
        printf("n[%d]: ", i);
        scanf("%d", &n[i]);
        printf("r[%d]: ", i);
        scanf("%d", &r[i]);
    }

    int result = solve_crt(n, r, k);
    printf("The smallest solution X is: %d\n", result);

    return 0;
}
