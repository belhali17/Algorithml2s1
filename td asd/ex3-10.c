#include <stdio.h>
#include <math.h>  // For sqrt function

// Function to compute the Euclidean distance between two vectors A and B
double euclidean_distance(int A[], int B[], int n) {
    double sum_of_squares = 0;

    // Compute the sum of the squared differences
    for (int i = 0; i < n; i++) {
        sum_of_squares += (A[i] - B[i]) * (A[i] - B[i]);
    }

    // Return the square root of the sum of squares
    return sqrt(sum_of_squares);
}

int main() {
    int n;

    // Input the size of the vectors
    printf("Enter the size of the vectors: ");
    scanf("%d", &n);

    int A[n], B[n];

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

    // Compute the Euclidean distance between A and B
    double distance = euclidean_distance(A, B, n);

    // Output the Euclidean distance
    printf("The Euclidean distance between A and B is: %.2f\n", distance);

    return 0;
}
