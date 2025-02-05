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

// Function to copy a doubly linked list
Node* copy(Node* head) {
    if (head == NULL) {
        return NULL;  // If the original list is empty, return NULL
    }

    // Create a new head node for the copied list
    Node* new_head = create_node(head->data);
    Node* current = head->next;
    Node* new_current = new_head;

    // Traverse the original list and copy each node
    while (current != NULL) {
        Node* new_node = create_node(current->data); // Create a new node
        new_current->next = new_node;  // Link the new node
        new_node->prev = new_current;  // Set the previous pointer
        new_current = new_node;        // Move the new list pointer forward
        current = current->next;      // Move the original list pointer forward
    }

    return new_head;  // Return the head of the copied list
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
    // Create a doubly linked list with 3 nodes
    Node* head = create_node(10);
    Node* node2 = create_node(20);
    Node* node3 = create_node(30);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;

    printf("Original list:\n");
    print_list_forward(head);

    // Copy the list
    Node* copied_list = copy(head);
    printf("Copied list:\n");
    print_list_forward(copied_list);

    return 0;
}
