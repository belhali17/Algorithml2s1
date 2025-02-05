#include <stdio.h>

// Function to merge two sorted arrays into a new sorted array
void merge(int L1[], int size1, int L2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Merge elements until one of the arrays is exhausted
    while (i < size1 && j < size2) {
        if (L1[i] < L2[j]) {
            result[k++] = L1[i++];
        } else {
            result[k++] = L2[j++];
        }
    }

    // Copy remaining elements from L1, if any
    while (i < size1) {
        result[k++] = L1[i++];
    }

    // Copy remaining elements from L2, if any
    while (j < size2) {
        result[k++] = L2[j++];
    }
}

// Main function to test the merge function
int main() {
    int L1[] = {1, 3, 5};
    int size1 = sizeof(L1) / sizeof(L1[0]);
    int L2[] = {2, 4, 6};
    int size2 = sizeof(L2) / sizeof(L2[0]);

    // Array to store the merged result
    int result[size1 + size2];

    // Merge the two lists
    merge(L1, size1, L2, size2, result);

    // Print the merged sorted list
    printf("Merged List: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
