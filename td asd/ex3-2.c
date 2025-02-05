#include <stdio.h>

// Function to compute the dot product of two vectors of size n
int dot_product(int A[], int B[], int n) {
    int sum = 0;

    // Compute the dot product by summing the products of corresponding elements
    for (int i = 0; i < n; i++) {
        sum += A[i] * B[i];  // Add the product of A[i] and B[i] to the sum
    }

    return sum;
}

int main() {
    int n;

    // Input the size of the vectors
    printf("Enter the size of the vectors: ");
    scanf("%d", &n);

    int A[n], B[n];

    // Input the elements of the first vector A
    printf("Enter the elements of vector A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Input the elements of the second vector B
    printf("Enter the elements of vector B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    // Compute the dot product of the two vectors
    int result = dot_product(A, B, n);

    // Output the result of the dot product
    printf("The dot product of the two vectors is: %d\n", result);

    return 0;
}
