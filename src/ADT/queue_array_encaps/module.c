// ADT/queue_array_encaps/module.c

#include <stdio.h>
#include <stdlib.h>
#include "module.h"

#define MAX_SIZE 100

struct queue {
    int data[MAX_SIZE];
    int FRONT, TAIL;
};

Queue *initializeQueue(void) {
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->FRONT = -1;
    queue->TAIL = -1;
    return queue;
}

bool isEmpty(const Queue *queue) {
    return queue == NULL || (queue->FRONT == -1 && queue->TAIL == -1);
}

bool isFull(const Queue *queue) {
    if (queue == NULL) {
        return false;
    }

    return (queue->TAIL + 1) % MAX_SIZE == queue->FRONT;
}

bool enqueue(Queue *queue, int value) {
    if (queue == NULL || isFull(queue)) {
        return false;
    }

    if (isEmpty(queue)) {
        queue->FRONT = 0;
        queue->TAIL = 0;
    } else {
        queue->TAIL = (queue->TAIL + 1) % MAX_SIZE;
    }
    queue->data[queue->TAIL] = value;

    return true;
}

bool dequeue(Queue *queue, int *value) {
    if (queue == NULL || value == NULL || isEmpty(queue)) {
        return false;
    }

    *value = queue->data[queue->FRONT];

    if (queue->FRONT == queue->TAIL) {
        queue->FRONT = -1;
        queue->TAIL = -1;
    } else {
        queue->FRONT = (queue->FRONT + 1) % MAX_SIZE;
    }

    return true;
}

void display(const Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->FRONT;
    do {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->TAIL + 1) % MAX_SIZE);
    printf("\n");
}

void deleteQueue(Queue *queue) {
    free(queue);
}
