#include <stdio.h>

// Function to compute the cross product of two 3D vectors
void cross_product(int A[], int B[], int result[]) {
    result[0] = A[1] * B[2] - A[2] * B[1];  // First component: (a2b3 - a3b2)
    result[1] = A[2] * B[0] - A[0] * B[2];  // Second component: (a3b1 - a1b3)
    result[2] = A[0] * B[1] - A[1] * B[0];  // Third component: (a1b2 - a2b1)
}

int main() {
    int A[3], B[3], result[3];

    // Input the components of the first vector A
    printf("Enter the components of vector A (a1, a2, a3): ");
    scanf("%d %d %d", &A[0], &A[1], &A[2]);

    // Input the components of the second vector B
    printf("Enter the components of vector B (b1, b2, b3): ");
    scanf("%d %d %d", &B[0], &B[1], &B[2]);

    // Compute the cross product
    cross_product(A, B, result);

    // Output the cross product result
    printf("The cross product of vectors A and B is: [%d, %d, %d]\n", result[0], result[1], result[2]);

    return 0;
}
