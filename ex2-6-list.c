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

// Function to find the middle node of the doubly linked list
Node* find_middle(Node* head) {
    if (head == NULL) {
        return NULL; // If the list is empty
    }

    Node* slow = head;
    Node* fast = head;

    // Traverse the list with two pointers: slow and fast
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      // Move slow pointer by one step
        fast = fast->next->next; // Move fast pointer by two steps
    }

    return slow; // When fast reaches the end, slow will be at the middle
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

    // Find the middle node
    Node* middle = find_middle(head);

    if (middle != NULL) {
        printf("Middle node: %d\n", middle->data);
    } else {
        printf("The list is empty.\n");
    }

    return 0;
}
