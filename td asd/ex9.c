#include <stdio.h>

// Function to compute the GCD of two numbers and find coefficients x and y
int extended_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a; // gcd(a, 0) = a
    }
    int x1, y1; // To store results of recursion
    int gcd = extended_gcd(b, a % b, &x1, &y1);

    // Update x and y using results of recursion
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

// Function to determine if the equation Ax + By = C has integer solutions
// and to find one such solution if it exists
int solve_diophantine(int A, int B, int C, int *x, int *y) {
    int gcd = extended_gcd(A, B, x, y);

    // Check if gcd(A, B) divides C
    if (C % gcd != 0) {
        return 0; // No solution
    }

    // Scale the solution x and y by C / gcd
    int scale = C / gcd;
    *x *= scale;
    *y *= scale;

    return 1; // Solution exists
}

int main() {
    int A, B, C;
    printf("Enter values for A, B, and C: ");
    scanf("%d %d %d", &A, &B, &C);

    int x, y;
    if (solve_diophantine(A, B, C, &x, &y)) {
        printf("The equation %d*x + %d*y = %d has a solution:\n", A, B, C);
        printf("x = %d, y = %d\n", x, y);
    } else {
        printf("The equation %d*x + %d*y = %d has no integer solutions.\n", A, B, C);
    }

    return 0;
}
