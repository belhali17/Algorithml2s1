#include <stdio.h>
#include <math.h>  // For dot product and magnitude functions

// Function to compute the dot product of two vectors A and B of size n
double dot_product(int A[], int B[], int n) {
    double result = 0;

    // Compute the dot product of A and B
    for (int i = 0; i < n; i++) {
        result += A[i] * B[i];
    }

    return result;
}

// Function to compute the projection of vector A onto vector B
void projection(int A[], int B[], int n, double proj[]) {
    // Compute the dot product A·B
    double dot_AB = dot_product(A, B, n);

    // Compute the dot product B·B (magnitude squared of B)
    double dot_BB = dot_product(B, B, n);

    // Compute the projection using the formula projB(A) = (A·B / B·B) * B
    double scalar = dot_AB / dot_BB;

    // Multiply each component of B by the scalar to get the projection
    for (int i = 0; i < n; i++) {
        proj[i] = scalar * B[i];
    }
}

int main() {
    int n;

    // Input the size of the vectors
    printf("Enter the size of the vectors: ");
    scanf("%d", &n);

    int A[n], B[n];
    double proj[n];

    // Input the components of vector A
    printf("Enter the components of vector A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Input the components of vector B
    printf("Enter the components of vector B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    // Compute the projection of A onto B
    projection(A, B, n, proj);

    // Output the projection vector
    printf("The projection of A onto B is:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", proj[i]);
    }
    printf("\n");

    return 0;
}
