#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void reverseDoublyLinkedList(Node** head) {
    Node* temp = NULL;
    Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

void insertAtPosition(Node** head, int k) {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    Node* newNode = createNode(value);
    if (k == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    Node* current = *head;
    int count = 0;
    while (current != NULL && count < k - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Error: Position %d out of bounds.\n", k);
        free(newNode);
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int pos;
    for (int i = 0; i < 5; i++) {
        printf("Enter position to insert: ");
        scanf("%d", &pos);
        insertAtPosition(&head, pos);
    }
    printList(head);
    reverseDoublyLinkedList(&head);
    printList(head);
    return 0;
}
