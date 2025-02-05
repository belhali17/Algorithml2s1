#include <stdio.h>

// Function to compute the sum of two vectors of size n
void vector_sum(int A[], int B[], int result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = A[i] + B[i];  // Sum the corresponding elements
    }
}

int main() {
    int n;

    // Input the size of the vectors
    printf("Enter the size of the vectors: ");
    scanf("%d", &n);

    int A[n], B[n], result[n];

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

    // Compute the sum of the two vectors
    vector_sum(A, B, result, n);

    // Output the result vector
    printf("The sum of the two vectors is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
