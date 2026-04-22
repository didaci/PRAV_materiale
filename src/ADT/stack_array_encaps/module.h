// ADT/stack_array_encasp/module.h

/* STACK
* Implementazione: array dinamico
 * CON incapsulamento completo
 *
 */

#ifndef MODULE_H
#define MODULE_H
#include <stdbool.h>

typedef struct stack Stack;


// Function prototypes

// Push element to the top of the stack
// PRECONDIZIONE: stack != NULL
bool push(Stack * stack, int val);

// Remove the top most element of the stack and store it in val
// PRECONDIZIONE: stack != NULL
bool pop(Stack * stack, int * val);

// Return the top most element of the stack and store it in val
// PRECONDIZIONE: stack != NULL
bool peek(Stack * stack, int * val);

// Check if the stack is in Underflow state or not
// PRECONDIZIONE: stack != NULL
bool isEmpty(Stack * stack);

Stack * initStack(int capacity); //INIT
void deleteStack(Stack * stack); // Free memory

// Check if the stack is in Overflow state or not
// PRECONDIZIONE: stack != NULL
bool isFull(Stack * stack);


// FOR DEBUG USE ONLY - REMOVE FROM THE INTERFACE
// PRECONDIZIONE: stack != NULL
void show(Stack * stack);
void automaticTest(void);

#endif //MODULE_H
