// ADT/stack_array_noencaps/module.c

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "module.h"


Stack * initStack(){
    Stack * stack= malloc(sizeof(*stack));
    if (!stack) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);  // Stop the program if malloc fails
    }
    stack->top=-1;
    return stack;
};

void deleteStack(Stack * p_s){
    // attenzione, dangling pointer
    //  il chiamante mantiene un puntatore dangling se non lo azzera con p=NULL
    free (p_s);
}

void push(Stack * stack, int val){

    stack->top+=1;
    stack->stackArray[stack->top] = val;
}

// PRECONDIZIONE: stack NON vuoto
int pop(Stack * stack){
    int val = stack->stackArray[stack->top];
    stack->top-=1;
    return val;
}

// PRECONDIZIONE: stack NON vuoto
int peek(Stack * stack){
    int val = stack->stackArray[stack->top];
    return val;
}

bool isEmpty(Stack * stack){  return stack->top==-1; }

bool isFull(Stack * stack){ return stack->top == STACK_MAX_SIZE-1; }

// FOR DEBUG USE ONLY - REMOVE FROM THE INTERFACE
void show(Stack * stack){
    int i;
    if (isEmpty( stack)) {
        printf("Empty stack!\n");
        return;
    }
    printf("[TOP] [");
    for (i=stack->top; i>=0; i--)
        printf("%d ",stack->stackArray[i]);
    printf("] [BASE]\n");
}




void automaticTest(void) {
    int value;
    Stack * s;
    s = initStack();
    printf("Automatic test\n");
    printf(" - check empty\n");
    assert(isEmpty(s));  //https://en.wikipedia.org/wiki/Assert.h
    printf(" - check push, pop, peek\n");
    // Push 1
    value=1;
    push(s, value);
    assert( !(isEmpty(s)));
    assert(value == peek(s));
    assert( !(isEmpty(s)));
    assert(value == pop(s));
    assert((isEmpty(s)));

    // Push 1, 2, 3
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("->expected: \n[TOP] [3 2 1] [BASE]\n");
    printf("->obtained:\n");
    show(s);
    assert( !(isEmpty(s)));
    assert(3 == peek(s));
    assert(3 == pop(s));
    assert(2 == peek(s));
    assert(2 == pop(s));
    assert(1 == peek(s));
    assert(1 == pop(s));
    assert((isEmpty(s)));

    printf("OK!\n");
    printf("--------------------\n");
    // Don't forget to free the memory!
    deleteStack(s);
}
