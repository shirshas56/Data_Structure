#include <stdio.h>
#include <stdlib.h>
#define MAX 5  

typedef struct {
    int items[MAX];
    int front, rear;
} CircularQueue;
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1;  
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("%d dequeued from the queue.\n", value);
    return value;
}
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    CircularQueue queue;
    initQueue(&queue);

    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
