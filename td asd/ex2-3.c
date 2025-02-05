#include <stdio.h>

// Function to generate the first N Fibonacci numbers
void generate_fibonacci(int N) {
    if (N <= 0) {
        printf("Invalid input. N must be greater than 0.\n");
        return;
    }

    long long first = 0, second = 1;

    // Handle the case for N = 1 separately
    if (N == 1) {
        printf("%lld\n", first);
        return;
    }

    printf("%lld, %lld", first, second);

    for (int i = 3; i <= N; i++) {
        long long next = first + second;
        printf(", %lld", next);
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    int N;

    // Input the number of terms
    printf("Enter the number of terms (N): ");
    scanf("%d", &N);

    // Generate and display the Fibonacci series
    generate_fibonacci(N);

    return 0;
}
