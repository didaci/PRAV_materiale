// ADT/queue_linked_list_encaps/module.h
#ifndef MODULE_H
#define MODULE_H

#include <stdbool.h>

typedef struct queue Queue;


Queue *initializeQueue(void);
bool isEmpty(const Queue *queue);
bool isFull(const Queue *queue);
bool enqueue(Queue *queue, int value);
bool dequeue(Queue *queue, int *value);
void deleteQueue(Queue *queue);
void show(const Queue *queue);  // DEBUG ONLY
#endif
