// ADT/queue_linked_list_encaps/main.c
#include <stdio.h>
#include <stdlib.h>
#include "module.h"
;


int main() {
    int value;

    Queue *q = initializeQueue();
    if (q == NULL) {
        printf("Unable to initialize queue\n");
        return 1;
    }
    printf("insert 10,20, 30, 40");

    if (!enqueue(q, 10) || !enqueue(q, 20) || !enqueue(q, 30) || !enqueue(q, 40)) {
        printf("Enqueue failed\n");
        deleteQueue(q);
        return 1;
    }

    show(q);

    if (!dequeue(q, &value)) {
        printf("Dequeue failed\n");
        deleteQueue(q);
        return 1;
    }
    printf("Dequeued element: %d\n", value);
    if (!dequeue(q, &value)) {
        printf("Dequeue failed\n");
        deleteQueue(q);
        return 1;
    }
    printf("Dequeued element: %d\n", value);

    show(q);

    printf("Destroy queue\n");
    deleteQueue(q);


    return 0;
}
