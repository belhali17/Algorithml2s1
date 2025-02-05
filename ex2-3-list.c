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

Node* delete(Node* head, int position) {
    if (head == NULL || position <= 0) {
        return head; // Invalid position or empty list
    }

    Node* temp = head;

    // Traverse to the node at the given position
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    // If the position is out of bounds
    if (temp == NULL) {
        return head;
    }

    // If the node to be deleted is the head
    if (temp == head) {
        head = temp->next;
    }

    // If the node to be deleted is not the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // If the node to be deleted is not the first node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp); // Free memory of the deleted node
    return head;
}

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
    // Create a doubly linked list with 4 nodes
    Node* head = create_node(10);
    Node* node2 = create_node(20);
    Node* node3 = create_node(30);
    Node* node4 = create_node(40);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;

    printf("Original List:\n");
    print_list_forward(head);

    // Delete the node at position 2
    head = delete(head, 2);
    printf("After deleting node at position 2:\n");
    print_list_forward(head);

    // Delete the node at position 1
    head = delete(head, 1);
    printf("After deleting node at position 1:\n");
    print_list_forward(head);

    return 0;
}
