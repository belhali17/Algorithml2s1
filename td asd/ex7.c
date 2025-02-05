#include <stdio.h>

// Function to compute (base^exp) % mod using modular exponentiation
long long modular_exponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; // Ensure base is within mod
    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        // Square the base
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to compute (A^B) % P using Fermat's Little Theorem
long long compute_mod(long long A, long long B, long long P) {
    if (A == 0) return 0; // If A is 0, the result is 0
    // Reduce B modulo (P-1) since P is prime
    long long reduced_exponent = B % (P - 1);
    // Compute (A^reduced_exponent) % P
    return modular_exponentiation(A, reduced_exponent, P);
}

int main() {
    long long A, B, P;
    printf("Enter values for A, B, and P (P should be prime): ");
    scanf("%lld %lld %lld", &A, &B, &P);

    long long result = compute_mod(A, B, P);
    printf("(A^B) %% P = %lld\n", result);

    return 0;
}
