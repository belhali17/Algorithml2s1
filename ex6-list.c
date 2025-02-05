#include <stdio.h>

// Function to reverse the elements of an array
void reverse(int L[], int size) {
    int start = 0;
    int end = size - 1;

    // Swap elements from start to end
    while (start < end) {
        int temp = L[start];
        L[start] = L[end];
        L[end] = temp;

        start++;
        end--;
    }
}

// Main function to test the reverse function
int main() {
    int L[] = {1, 2, 3, 4, 5};
    int size = sizeof(L) / sizeof(L[0]);

    printf("Original List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", L[i]);
    }

    reverse(L, size);

    printf("\nReversed List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", L[i]);
    }

    return 0;
}
