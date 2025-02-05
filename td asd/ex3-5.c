#include <stdio.h>
#include <math.h>  // For the sqrt function

// Function to compute the magnitude (length) of a vector of size n
double vector_magnitude(int A[], int n) {
    double sum_of_squares = 0;

    // Compute the sum of the squares of the components
    for (int i = 0; i < n; i++) {
        sum_of_squares += A[i] * A[i];
    }

    // Return the square root of the sum of squares
    return sqrt(sum_of_squares);
}

// Function to normalize a given vector A of size n
void normalize_vector(int A[], int n, double B[]) {
    // Compute the magnitude of the vector A
    double magnitude = vector_magnitude(A, n);

    // Normalize each component of the vector A to get the vector B
    for (int i = 0; i < n; i++) {
        B[i] = A[i] / magnitude;
    }
}

int main() {
    int n;

    // Input the size of the vector
    printf("Enter the size of the vector: ");
    scanf("%d", &n);

    int A[n];
    double B[n];

    // Input the components of the vector A
    printf("Enter the components of vector A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Normalize the vector
    normalize_vector(A, n, B);

    // Output the normalized vector B
    printf("The normalized vector B is:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", B[i]);
    }
    printf("\n");

    return 0;
}
