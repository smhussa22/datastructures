#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Queue {

    int front, rear, capacity;
    int storage[MAX];

};

void enqueue(struct Queue* queue, int value);
void dequeue(struct Queue* queue);
void printQueue(struct Queue* queue);

int main(){

    struct Queue queue;
    queue.front = 0;
    queue.rear = -1;
    queue.capacity = 5;

    for (int i = 0; i < 3; i++){

        enqueue(&queue, i + 1);

    }

    printQueue(&queue);
    dequeue(&queue);
    printQueue(&queue);

    return 0;

}

void enqueue(struct Queue* queue, int value){

    if(queue->rear == queue->capacity - 1) return;
    queue->rear++;
    printf("Enqueueing %d...\n", value);
    queue->storage[queue->rear] = value;

}

void dequeue(struct Queue* queue){

    if(queue->rear == -1) return;
    printf("Dequeuing %d...\n", queue->storage[queue->front]);
    queue->front++;

}

void printQueue(struct Queue* queue){

    if(queue->rear == -1) return;

    printf("Queue: ");

    for (int i = queue->front; i <= queue->rear; i++){

        printf("%d\t", queue->storage[i]);

    }

    printf("\n");

}