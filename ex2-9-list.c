#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to find the k-th node from the end of the doubly linked list
Node* kth_from_end(Node* head, int k) {
    if (head == NULL || k <= 0) {
        return NULL; // Invalid input or empty list
    }

    Node* temp = head;
    int length = 0;

    // Calculate the length of the list
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // Check if k is larger than the length of the list
    if (k > length) {
        return NULL; // k is out of range
    }

    temp = head;

    // Traverse the list to find the (length - k + 1)-th node
    for (int i = 1; i < length - k + 1; i++) {
        temp = temp->next;
    }

    return temp; // Return the k-th node from the end
}

// Function to print the list forward
void print_list_forward(Node* head) {
    Node* temp = head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a doubly linked list with 5 nodes
    Node* head = create_node(10);
    Node* node2 = create_node(20);
    Node* node3 = create_node(30);
    Node* node4 = create_node(40);
    Node* node5 = create_node(50);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    printf("Original list:\n");
    print_list_forward(head);

    int k = 2;
    Node* kth_node = kth_from_end(head, k);

    if (kth_node != NULL) {
        printf("The %d-th node from the end is: %d\n", k, kth_node->data);
    } else {
        printf("Invalid position: k is out of range.\n");
    }

    return 0;
}
