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

// Function to traverse the list backward
void traverse_backward(Node* tail) {
    Node* temp = tail;
    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    // Create a doubly linked list with 3 nodes
    Node* head = create_node(10);
    Node* node2 = create_node(20);
    Node* node3 = create_node(30);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;

    // Find the tail of the list
    Node* tail = node3;

    // Traverse and print the list backward
    traverse_backward(tail);

    return 0;
}
