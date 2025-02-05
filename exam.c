#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(Node** head, int value, int k) {
    Node* newNode = createNode(value);
    if (k == 0) {
        newNode->next = *head;
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
    current->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    insertAtPosition(&head, 10, 0);
    insertAtPosition(&head, 20, 1);
    insertAtPosition(&head, 30, 1);
    insertAtPosition(&head, 40, 0);
    insertAtPosition(&head, 50, 10);
    printList(head);
    return 0;
}
