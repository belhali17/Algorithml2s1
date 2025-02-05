#include <stdio.h>

// Function to compute the dot product of two vectors A and N of size n
double dot_product(int A[], int N[], int n) {
    double result = 0;

    // Compute the dot product of A and N
    for (int i = 0; i < n; i++) {
        result += A[i] * N[i];
    }

    return result;
}

// Function to compute the reflection of vector A off the surface represented by normal N
void reflection(int A[], int N[], int n, double R[]) {
    // Compute the dot product A·N
    double dot_AN = dot_product(A, N, n);

    // Compute the reflection using the formula R = A - 2 * (A·N) * N
    for (int i = 0; i < n; i++) {
        R[i] = A[i] - 2 * dot_AN * N[i];
    }
}

int main() {
    int n;

    // Input the size of the vectors
    printf("Enter the size of the vectors: ");
    scanf("%d", &n);

    int A[n], N[n];
    double R[n];

    // Input the components of vector A
    printf("Enter the components of vector A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Input the components of the normal vector N
    printf("Enter the components of normal vector N:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &N[i]);
    }

    // Compute the reflection of A off the surface represented by N
    reflection(A, N, n, R);

    // Output the reflection vector R
    printf("The reflection of vector A off the surface is:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", R[i]);
    }
    printf("\n");

    return 0;
}
