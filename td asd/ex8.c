#include <stdio.h>
#include <math.h>

// Function to compute the sum of all divisors of N
long long sum_of_divisors(int N) {
    long long sum = 0;
    // Iterate from 1 to sqrt(N)
    for (int i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            sum += i; // Add the divisor
            if (i != N / i) { // Add the corresponding pair divisor
                sum += N / i;
            }
        }
    }
    return sum;
}

int main() {
    int N;
    printf("Enter a number N (1 ≤ N ≤ 10^6): ");
    scanf("%d", &N);

    if (N < 1 || N > 1000000) {
        printf("N is out of range!\n");
        return 1;
    }

    long long result = sum_of_divisors(N);
    printf("The sum of all divisors of %d is: %lld\n", N, result);

    return 0;
}
