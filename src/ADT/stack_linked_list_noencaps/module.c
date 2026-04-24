// ADT/stack_linked_list_noencaps/module.c

#include <stdio.h>
#include <stdlib.h>
#include "module.h"



Stack *initStack(void) {
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }

    stack->head = NULL;
    stack->numberOfElements = 0;

    return stack;
}

bool isEmpty(const Stack *stack) {
    return stack == NULL || stack->head == NULL;
}

bool push(Stack *stack, int val) {
    if (stack == NULL) {
        return false;
    }

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }

    newNode->value = val;
    newNode->next = stack->head;
    stack->head = newNode;
    stack->numberOfElements++;

    return true;
}

bool pop(Stack *stack, int *val) {
    if (stack == NULL || val == NULL || isEmpty(stack)) {
        return false;
    }

    Node *temp = stack->head;
    *val = temp->value;
    stack->head = temp->next;
    stack->numberOfElements--;

    free(temp);
    return true;
}

bool peek(const Stack *stack, int *val) {
    if (stack == NULL || val == NULL || isEmpty(stack)) {
        return false;
    }

    *val = stack->head->value;
    return true;
}

void show(Stack *stack) {
    // FOR DEBUG USE ONLY - REMOVE FROM THE INTERFACE

    /*
     * This function prints the stack values starting from TOP.
     * We will see later how to print starting from Base
     * */

    Node *tmpNode;
    if (isEmpty(stack)) {
        printf("Empty stack\n");
        return;
    }
    tmpNode = stack->head;
    printf("[TOP] [");
    do {
        printf("%d ", tmpNode->value);
    } while ((tmpNode = tmpNode->next));
    printf("] [BASE]\n");
}

void deleteStack(Stack *stack) {
    if (stack == NULL) {
        return;
    }

    Node *current = stack->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(stack);
}
