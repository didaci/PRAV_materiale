// ADT/stack_linked_list_encaps/module.h


#ifndef MODULE_H
#define MODULE_H

#include <stdbool.h>



typedef struct stack Stack;

// Function prototypes
Stack *initStack(void);

bool push(Stack *stack, int val);
bool pop(Stack *stack, int *val);
bool peek(const Stack *stack, int *val);

bool isEmpty(const Stack *stack);

void deleteStack(Stack *stack);

// FOR DEBUG USE ONLY - REMOVE FROM THE INTERFACE
void show(Stack *stack);


#endif //MODULE_H
