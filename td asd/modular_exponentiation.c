#include <stdio.h>

// Function to perform modular exponentiation
// It returns (A^B) % M
long long modular_exponentiation(long long A, long long B, long long M) {
    long long result = 1;   // Initialize result
    A = A % M;              // Update A if A >= M

    while (B > 0) {
        // If B is odd, multiply A with result
        if (B % 2 == 1) {
            result = (result * A) % M;
        }

        // B must be even now, divide it by 2
        B = B / 2;

        // Change A to A^2
        A = (A * A) % M;
    }

    return result;
}

int main() {
    long long A, B, M;

    // Input values for A, B, and M
    printf("Enter values for A, B, and M: ");
    scanf("%lld %lld %lld", &A, &B, &M);

    // Compute (A^B) % M
    long long result = modular_exponentiation(A, B, M);

    // Output the result
    printf("(A^B) %% M = %lld\n", result);

    return 0;
}
