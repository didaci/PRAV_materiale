// ADT/queue_linked_list_encaps/module.c

#include <stdlib.h>
#include <stdio.h>
#include "module.h"

typedef struct node {
    int value;
    struct node *next;
}Node;

struct queue {
    Node *front;
    Node *tail;
    int numberOfElements; // optional
};

// private function
static Node *createNewNode(Node *next, int val) {
    Node *newNode = malloc(sizeof(*newNode));
    if (newNode == NULL) {
        return NULL;
    }

    newNode->next = next;
    newNode->value = val;
    return newNode;
}

Queue *initializeQueue(void) {
    Queue *queue = malloc(sizeof(*queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->front = NULL;
    queue->tail = NULL;
    queue->numberOfElements = 0; // optional
    return queue;
}

bool isEmpty(const Queue *queue) {
    return queue == NULL || queue->front == NULL;
    //return q->numberOfElements == 0;
}

bool isFull(const Queue *queue) {
    return false;
}

bool enqueue(Queue *queue, int value) {
    if (queue == NULL) {
        return false;
    }

    Node *newNode = createNewNode(NULL, value);
    if (newNode == NULL) {
        return false;
    }
    queue->numberOfElements += 1;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->tail = newNode;
     } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
     }

    return true;
}

bool dequeue(Queue *queue, int *value) {
    if (queue == NULL || value == NULL || isEmpty(queue)) {
        return false;
    }

    *value = queue->front->value;
    Node *p_tmp = queue->front;

    if (queue->tail == queue->front) {
        queue->front = NULL;
        queue->tail = NULL;
    }
    else {
        queue->front = queue->front->next;
    }
    free(p_tmp);
    queue->numberOfElements -= 1;
    return true;
}

void deleteQueue(Queue *queue) {
    if (queue == NULL) {
        return;
    }

    while (!isEmpty(queue)) {
        Node *current = queue->front;
        queue->front = current->next;
        free(current);
    }
    free(queue);
}

void show(const Queue *queue) {  // DEBUG ONLY
    if (queue == NULL) {
        printf("Queue: <null>\n");
        return;
    }

    printf("Queue: ");
    const Node *current = queue->front;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

}
