// ADT/stack_array_encasp/module.c

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "module.h"

struct stack {
    int *data;
    int top;
    int capacity;
};


Stack *initStack(int capacity) {
    if (capacity <= 0) return NULL;

    Stack *s = malloc(sizeof(Stack));
    if (s == NULL) return NULL;

    s->data = malloc(capacity * sizeof(int));
    if (s->data == NULL) {
        free(s);
        return NULL;
    }

    s->top = -1;
    s->capacity = capacity;

    return s;
}

void deleteStack(Stack *s) {
    if (s == NULL) return;

    free(s->data);
    free(s);
}

bool push(Stack * stack, int val){
    if (isFull(stack)) {
        return false;
    }

    stack->top+=1;
    stack->data[stack->top] = val;
    return true;
}

bool pop(Stack *stack, int * val){
    if (val == NULL || isEmpty(stack)) {
        return false;
    }

    *val = stack->data[stack->top];
    stack->top--;
    return true;
}

bool peek(Stack * stack, int * val){
    if (val == NULL || isEmpty(stack)) {
        return false;
    }

    *val = stack->data[stack->top];
    return true;
}

bool isEmpty(Stack * stack){  return stack->top==-1; }

bool isFull(Stack * stack){ return stack->top == stack->capacity-1; }

// FOR DEBUG USE ONLY - REMOVE FROM THE INTERFACE
void show(Stack * stack){
    int i;
    if (isEmpty( stack)) {
        printf("Empty stack!\n");
        return;
    }
    printf("[TOP] [");
    for (i=stack->top; i>=0; i--)
        printf("%d ",stack->data[i]);
    printf("] [BASE]\n");
}




void automaticTest(void) {
    int value;
    int peekedValue;
    int poppedValue;
    Stack * s;
    s = initStack(10);
    assert(s != NULL);
    printf("Automatic test\n");
    printf(" - check empty\n");
    assert(isEmpty(s));  //https://en.wikipedia.org/wiki/Assert.h
    printf(" - check push, pop, peek\n");
    // Push 1
    value=1;
    assert(push(s, value));
    assert( !(isEmpty(s)));
    assert(peek(s, &peekedValue));
    assert(value == peekedValue);
    assert( !(isEmpty(s)));
    assert(pop(s, &poppedValue));
    assert(value == poppedValue);
    assert((isEmpty(s)));

    // Push 1, 2, 3
    assert(push(s, 1));
    assert(push(s, 2));
    assert(push(s, 3));
    printf("->expected: \n[TOP] [3 2 1] [BASE]\n");
    printf("->obtained:\n");
    show(s);
    assert( !(isEmpty(s)));
    assert(peek(s, &peekedValue));
    assert(3 == peekedValue);
    assert(pop(s, &poppedValue));
    assert(3 == poppedValue);
    assert(peek(s, &peekedValue));
    assert(2 == peekedValue);
    assert(pop(s, &poppedValue));
    assert(2 == poppedValue);
    assert(peek(s, &peekedValue));
    assert(1 == peekedValue);
    assert(pop(s, &poppedValue));
    assert(1 == poppedValue);
    assert((isEmpty(s)));

    printf("OK!\n");
    printf("--------------------\n");
    // Don't forget to free the memory!
    deleteStack(s);
}
