#include <stdio.h>

// Function to multiply a vector A by a scalar k
void scalar_multiply(int A[], int n, int k, int result[]) {
    // Multiply each component of A by the scalar k
    for (int i = 0; i < n; i++) {
        result[i] = A[i] * k;
    }
}

int main() {
    int n, k;

    // Input the size of the vector
    printf("Enter the size of the vector: ");
    scanf("%d", &n);

    int A[n], result[n];

    // Input the components of vector A
    printf("Enter the components of vector A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Input the scalar value k
    printf("Enter the scalar k: ");
    scanf("%d", &k);

    // Multiply vector A by scalar k
    scalar_multiply(A, n, k, result);

    // Output the resulting vector
    printf("The resulting vector after multiplication by k is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
