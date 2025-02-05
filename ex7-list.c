#include <stdio.h>

// Function to sort an array in ascending order using Bubble Sort
void sort(int L[], int size) {
    for (int i = 0; i < size - 1; i++) {         // Outer loop for passes
        for (int j = 0; j < size - i - 1; j++) { // Inner loop for comparisons
            if (L[j] > L[j + 1]) {               // Swap if elements are out of order
                int temp = L[j];
                L[j] = L[j + 1];
                L[j + 1] = temp;
            }
        }
    }
}

// Main function to test the sort function
int main() {
    int L[] = {5, 3, 8, 1, 2};
    int size = sizeof(L) / sizeof(L[0]);

    printf("Original List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", L[i]);
    }

    sort(L, size);

    printf("\nSorted List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", L[i]);
    }

    return 0;
}
