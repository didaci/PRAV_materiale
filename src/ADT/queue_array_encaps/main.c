// ADT/queue_array_encaps/main.c


#include <stdio.h>
#include "module.h"

int main() {
    int value;
    Queue *queue = initializeQueue(5);
    if (queue == NULL) {
        printf("Unable to initialize queue.\n");
        return 1;
    }

    if (!enqueue(queue, 10) || !enqueue(queue, 20) || !enqueue(queue, 30)) {
        printf("Enqueue failed.\n");
        deleteQueue(queue);
        return 1;
    }

    display(queue);

    if (!dequeue(queue, &value)) {
        printf("Dequeue failed.\n");
        deleteQueue(queue);
        return 1;
    }
    printf("Dequeued element: %d\n", value);

    display(queue);
    deleteQueue(queue);

    return 0;
}
