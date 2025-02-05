#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool is_prime(long long N) {
    if (N <= 1) return false;
    if (N <= 3) return true;
    if (N % 2 == 0 || N % 3 == 0) return false;

    for (long long i = 5; i * i <= N; i += 6) {
        if (N % i == 0 || N % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    long long N;
    printf("Enter a number: ");
    scanf("%lld", &N);

    if (is_prime(N)) {
        printf("%lld is a prime number.\n", N);
    } else {
        printf("%lld is not a prime number.\n", N);
    }

    return 0;
}
