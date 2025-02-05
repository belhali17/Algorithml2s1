#include <stdio.h>
#include <math.h>  // For sqrt, acos, and M_PI functions

// Function to compute the dot product of two vectors A and B of size n
double dot_product(int A[], int B[], int n) {
    double result = 0;

    // Compute the dot product of A and B
    for (int i = 0; i < n; i++) {
        result += A[i] * B[i];
    }

    return result;
}

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

// Function to compute the angle between two vectors A and B in radians
double compute_angle(int A[], int B[], int n, int in_degrees) {
    // Compute the dot product of A and B
    double dot = dot_product(A, B, n);

    // Compute the magnitudes of A and B
    double magnitude_A = vector_magnitude(A, n);
    double magnitude_B = vector_magnitude(B, n);

    // Compute the cosine of the angle between A and B
    double cos_theta = dot / (magnitude_A * magnitude_B);

    // Ensure the cosine value is within the valid range for acos (-1 <= cos <= 1)
    if (cos_theta > 1) cos_theta = 1;
    if (cos_theta < -1) cos_theta = -1;

    // Compute the angle in radians
    double angle_radians = acos(cos_theta);

    // If in_degrees is 1, convert the angle to degrees
    if (in_degrees) {
        return angle_radians * (180.0 / M_PI);
    }

    return angle_radians;  // Return the angle in radians
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

    int in_degrees;
    // Choose whether to output the angle in degrees or radians
    printf("Do you want the angle in degrees? (1 for yes, 0 for no): ");
    scanf("%d", &in_degrees);

    // Compute the angle between the vectors
    double angle = compute_angle(A, B, n, in_degrees);

    // Output the result
    if (in_degrees) {
        printf("The angle between the vectors in degrees is: %.2f\n", angle);
    } else {
        printf("The angle between the vectors in radians is: %.2f\n", angle);
    }

    return 0;
}
