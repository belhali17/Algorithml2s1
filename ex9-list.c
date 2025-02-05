#include <stdio.h>

// Function to remove duplicates from a sorted array
int remove_duplicates(int L[], int size) {
    if (size == 0) return 0; // If the array is empty

    int j = 0; // Pointer for the unique elements

    for (int i = 1; i < size; i++) {
        if (L[i] != L[j]) { // Found a unique element
            j++;           // Move the pointer for unique elements
            L[j] = L[i];   // Update the position with the unique element
        }
    }
    return j + 1; // New size of the array
}

// Main function to test remove_duplicates
int main() {
    int L[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int size = sizeof(L) / sizeof(L[0]);

    printf("Original List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", L[i]);
    }

    // Remove duplicates
    int new_size = remove_duplicates(L, size);

    printf("\nList After Removing Duplicates: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", L[i]);
    }

    return 0;
}
