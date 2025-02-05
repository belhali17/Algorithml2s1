#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue structure
typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmptyQueue(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

int frontQueue(Queue *q) {
    return isEmptyQueue(q) ? -1 : q->items[q->front];
}

// Stack using a single queue
typedef struct {
    Queue q;
} StackSingleQueue;

void initStackSingle(StackSingleQueue *s) {
    initQueue(&s->q);
}

void pushSingle(StackSingleQueue *s, int value) {
    enqueue(&s->q, value);
    for (int i = 0; i < s->q.rear; i++) {
        enqueue(&s->q, dequeue(&s->q));
    }
}

int popSingle(StackSingleQueue *s) {
    return dequeue(&s->q);
}

int peekSingle(StackSingleQueue *s) {
    return frontQueue(&s->q);
}

int isEmptySingle(StackSingleQueue *s) {
    return isEmptyQueue(&s->q);
}

// Stack using two queues
typedef struct {
    Queue q1, q2;
} StackTwoQueues;

void initStackTwo(StackTwoQueues *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void pushTwo(StackTwoQueues *s, int value) {
    enqueue(&s->q2, value);
    while (!isEmptyQueue(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int popTwo(StackTwoQueues *s) {
    return dequeue(&s->q1);
}

int peekTwo(StackTwoQueues *s) {
    return frontQueue(&s->q1);
}

int isEmptyTwo(StackTwoQueues *s) {
    return isEmptyQueue(&s->q1);
}

int main() {
    StackSingleQueue s1;
    StackTwoQueues s2;
    int value;

    initStackSingle(&s1);
    initStackTwo(&s2);

    printf("Enter values to push into the stack (enter -1 to stop):\n");
    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);
        if (value == -1) break;
        pushSingle(&s1, value);
        pushTwo(&s2, value);
    }

    printf("Single Queue Stack Pop: %d\n", popSingle(&s1));
    printf("Single Queue Stack Peek: %d\n", peekSingle(&s1));

    printf("Two Queue Stack Pop: %d\n", popTwo(&s2));
    printf("Two Queue Stack Peek: %d\n", peekTwo(&s2));

    return 0;
}
