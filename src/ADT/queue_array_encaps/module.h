// ADT/queue_array_encaps/module.h

#ifndef MODULE_H
#define MODULE_H

#include <stdbool.h>

typedef struct queue Queue;

Queue *initializeQueue(void);

bool isEmpty(const Queue *queue);
bool isFull(const Queue *queue);

bool enqueue(Queue *queue, int value);
bool dequeue(Queue *queue, int *value);

void display(const Queue *queue);
void deleteQueue(Queue *queue);

#endif
