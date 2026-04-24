// ADT/stack_linked_list_noencaps/main.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "module.h"

// Implementing Dynamic Stack using structs and pointers in C
// YOU CAN bypass the interface and break encapsulation:
// s-> ...
// *s  ...

void automaticTest(void);
void use(void);
// MAIN
int main (){
    int choice;

    printf("DYNAMIC STACK");
    printf("\nChoose any of the following options:\n");
    printf("   1: Automatic test            2: use \n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: automaticTest(); break;
        case 2: use(); break;
        default: printf("bye\n");
    }

    printf("bye!");
    return 0;
} // end main

void use(void){
    int choice=0;
    int value;
    Stack *s = initStack();
    if (s == NULL) {
        printf("Unable to initialize stack\n");
        return;
    }

    do {
        printf("\n------------------------------------\n");
        printf("Choose any of the following options:\n");
        printf(" 0: Exit            1: Push            2: Pop            3: Peek\n");
        printf(" 4: Check if the stack is empty    5: Delete stack\n");
        printf(" 6: Check if the stack is full     9: Show contents\n");
        scanf("%d", &choice);
        switch(choice) {
            case 0: break;
            case 1: {
                printf("Insert a value\n"); scanf("%d", &value);
                push(s, value); show(s);
                break;
            }
            case 2: {
                if (pop(s, &value)) {
                    printf("pop->%d\n", value);
                } else {
                    printf("pop failed\n");
                }
                show(s);
                break;
            }
            case 3: {
                if (peek(s, &value)) {
                    printf("peek->%d\n", value);
                } else {
                    printf("peek failed\n");
                }
                show(s);
                break;
            }
            case 4:
                printf("%s\n", isEmpty(s) ? "stack EMPTY": "stack NOT EMPTY");
                break;
            case 5:
                deleteStack(s);
                s = initStack();
                if (s == NULL) {
                    printf("Unable to initialize stack\n");
                    return;
                }
                break;
            case 6: printf("Not applicable\n"); break;
            case 9: show(s); break;
            default: printf("Please choose a correct option!");
        }
    }while (choice!=0);

    // Don't forget to free the memory!
    deleteStack(s);
}


void automaticTest(void){
    int value;
    Stack *s = initStack();
    if (s == NULL) {
        printf("Unable to initialize stack\n");
        return;
    }
    printf("Automatic test\n");




    printf("Push 1 2 3 4 5 6 \n");
    printf("->expected: \n[TOP] [6 5 4 3 2 1] [BASE]");
    for (int i = 1; i < 7; i++) {
        if (!push(s, i)) {
            printf("\npush failed for value %d\n", i);
            deleteStack(s);
            return;
        }
    }
    printf("\n->obtained:\n");
    show(s);
    printf("--------------------\n");

    printf("pop; pop; peek \n");
    printf("->expected: out: 6; out: 5; out: 4;  \n[TOP] [4 3 2 1] [BASE]");
    printf("\n->obtained:\n");
    if (!pop(s, &value)) {
        printf("pop failed\n");
        deleteStack(s);
        return;
    }
    printf(" out:%d,", value);
    if (!pop(s, &value)) {
        printf("pop failed\n");
        deleteStack(s);
        return;
    }
    printf("out: %d,", value);
    if (!peek(s, &value)) {
        printf("peek failed\n");
        deleteStack(s);
        return;
    }
    printf("out: %d\n ", value);
    show(s);

    printf("--------------------\n");
    printf("Push 5 6 \n");
    printf("->expected: \n[TOP] [6 5 4 3 2 1] [BASE]");
    if (!push(s, 5)) {
        printf("\npush failed for value 5\n");
        deleteStack(s);
        return;
    }
    if (!push(s, 6)) {
        printf("\npush failed for value 6\n");
        deleteStack(s);
        return;
    }
    printf("\n->obtained:\n");
    show(s);

    printf("--------------------\n");
    // Don't forget to free the memory!
    deleteStack(s);



}
