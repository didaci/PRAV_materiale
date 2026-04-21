// ADT/stack_array_noencasp/module.h

/* STACK
* Implementazione: array statico
 * SENZA incapsulamento completo
 *
 * È possibile aggirare l’interfaccia e violare l’incapsulamento:
 * s->stackArray[0] = 10;
 * s->top = 0;
 *
 * L’implementazione utilizza un array contenuto in una struttura.
 * L’allocazione della struttura è dinamica, ma questo è solo un dettaglio implementativo.
 * Modificando initStack si potrebbe ottenere un’implementazione completamente statica.
 */

#ifndef MODULE_H
#define MODULE_H
#include <stdbool.h>

/*
 * il .h deve incliudere altri .h  solo se strettamente necessario.
 * La libreria <stdbool.h> definisce
 *    il tipo di dato booleano bool
 *    le costanti true (1) e false (0).
 * Viene usato dall'interfaccia, quindi è necessario includerlo
 */

/* STACK_MAX_SIZE -> capacity of the Static Stack
 * STACK_MAX_SIZE is part of the interface
 * and it is visible from main()
 */
#define STACK_MAX_SIZE 1000

typedef struct stack {
    int stackArray[STACK_MAX_SIZE];
    int top;
}Stack;

// Function prototypes

// Push element to the top of the stack
// PRECONDIZIONE: stack NON pieno
void push(Stack * stack, int val);

// Remove and return the top most element of the stack
// PRECONDIZIONE: stack NON vuoto
int pop(Stack * stack);

// Return the top most element of the stack
// PRECONDIZIONE: stack NON vuoto
int peek(Stack * stack);

// Check if the stack is in Underflow state or not
bool isEmpty(Stack * stack);

Stack * initStack(); //INIT
void deleteStack(Stack * stack); // Free memory

// Check if the stack is in Overflow state or not
// ONLY FOR STATIC ARRAY IMPLEMENTATION
bool isFull(Stack * stack);


// FOR DEBUG USE ONLY - REMOVE FROM THE INTERFACE
void show(Stack * stack);
void automaticTest(void);

#endif //MODULE_H
