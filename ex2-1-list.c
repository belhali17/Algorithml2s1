#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
typedef struct Node {
    int data;               // Data of the node
    struct Node* prev;      // Pointer to the previous node
    struct Node* next;      // Pointer to the next node
} Node;

// Function to create a new node
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node)); // Allocate memory for the node
    new_node->data = value;                      // Assign the value
    new_node->prev = NULL;                       // Initialize prev as NULL
    new_node->next = NULL;                       // Initialize next as NULL
    return new_node;
}

// Function to initialize the doubly linked list with 3 nodes
Node* initialize_list() {
    // Create 3 nodes
    Node* node1 = create_node(10); // First node with value 10
    Node* node2 = create_node(20); // Second node with value 20
    Node* node3 = create_node(30); // Third node with value 30

    // Link the nodes
    node1->next = node2; // node1's next points to node2
    node2->prev = node1; // node2's prev points to node1
    node2->next = node3; // node2's next points to node3
    node3->prev = node2; // node3's prev points to node2

    // Return the head of the list (node1)
    return node1;
}

// Function to print the list from head to tail
void print_list_forward(Node* head) {
    Node* temp = head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the list from tail to head
void print_list_backward(Node* tail) {
    Node* temp = tail;
    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function to test the doubly linked list
int main() {
    // Initialize the list with 3 nodes
    Node* head = initialize_list();

    // Traverse to the tail of the list
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Print the list forward and backward
    print_list_forward(head);
    print_list_backward(tail);

    return 0;
}
