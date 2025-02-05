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

// Function to detect if a doubly linked list contains a cycle
int has_cycle(Node* head) {
    if (head == NULL) {
        return 0; // No cycle in an empty list
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // Move slow pointer one step
        fast = fast->next->next;  // Move fast pointer two steps

        if (slow == fast) {  // If they meet, there is a cycle
            return 1;  // Cycle detected
        }
    }

    return 0;  // No cycle detected
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

    // Uncomment the next line to create a cycle for testing
    // node5->next = node3;  // Creating a cycle: node5 points to node3

    // Check for cycle
    if (has_cycle(head)) {
        printf("The list contains a cycle.\n");
    } else {
        printf("The list does not contain a cycle.\n");
    }

    return 0;
}
