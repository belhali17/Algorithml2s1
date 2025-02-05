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

int main() {
    int n;

    // Input the size of the vector
    printf("Enter the size of the vector: ");
    scanf("%d", &n);

    int A[n];

    // Input the components of the vector A
    printf("Enter the components of vector A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Compute the magnitude of the vector
    double magnitude = vector_magnitude(A, n);

    // Output the magnitude of the vector
    printf("The magnitude of the vector is: %.2f\n", magnitude);

    return 0;
}
