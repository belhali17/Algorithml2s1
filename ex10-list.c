#include <stdio.h>

// Function to partition the array for QuickSelect
int partition(int L[], int low, int high) {
    int pivot = L[high];  // Choose the last element as the pivot
    int i = low - 1;

    // Rearrange elements so that elements greater than pivot are on the left
    for (int j = low; j < high; j++) {
        if (L[j] >= pivot) {  // We want to find the k-th largest, so we check for greater elements
            i++;
            // Swap L[i] and L[j]
            int temp = L[i];
            L[i] = L[j];
            L[j] = temp;
        }
    }

    // Swap pivot to its correct position
    int temp = L[i + 1];
    L[i + 1] = L[high];
    L[high] = temp;

    return i + 1;
}

// Function to find the k-th largest element using QuickSelect
int kth_largest(int L[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(L, low, high);

        // If the pivot position is the k-th largest element
        if (pi == k - 1) {
            return L[pi];
        }
        // If the pivot is greater than k-th largest, we search in the left part
        else if (pi > k - 1) {
            return kth_largest(L, low, pi - 1, k);
        }
        // Otherwise, search in the right part
        else {
            return kth_largest(L, pi + 1, high, k);
        }
    }
    return -1; // In case k is out of bounds
}

// Main function to test kth_largest
int main() {
    int L[] = {12, 3, 5, 7, 19, 1, 6};
    int size = sizeof(L) / sizeof(L[0]);
    int k = 4;

    printf("The %d-th largest element is: %d\n", k, kth_largest(L, 0, size - 1, k));

    return 0;
}
