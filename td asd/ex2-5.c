#include <stdio.h>

// Function to compute the n-th triangular number
int triangular_number(int n) {
    if (n <= 0) {
        return 0; // Invalid input for n
    }
    // Use the formula: T_n = n * (n + 1) / 2
    return n * (n + 1) / 2;
}

int main() {
    int n;

    // Input the number
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n must be a positive integer.\n");
        return 1;
    }

    // Compute the n-th triangular number
    int result = triangular_number(n);
    printf("The %d-th triangular number is: %d\n", n, result);

    return 0;
}
