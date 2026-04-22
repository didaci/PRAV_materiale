// ADT/stack_array_noencaps/main.c

#include <stdio.h>
#include <assert.h>
#include "module.h"


void use(void);
// MAIN
int main (){
    int choice;

    printf("STATIC STACK");
    printf("\nChoose any of the following options:\n");
    printf("   1: Automatic test            2: Use \n");
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
    Stack * s;
    s= initStack();
    //s->stackArray[0]=10;
    //s->top=0;

    do {
        printf("\n------------------------------------\n");
        printf("Choose any of the following options:\n");
        printf(" 0: Exit            1: Push            2: Pop            3: Peek\n");
        printf(" 4: Check if the stack is empty    5: Empty stack\n");
        printf(" 6: Check if the stack is full     9: Show contents\n");
        scanf("%d", &choice);
        switch(choice) {
            case 0: break;
            case 1: {
                printf("PUSH -Insert a value\n"); scanf("%d", &value);
                push(s,value); show(s);
                break;
            }
            case 2: {
                printf("POP->%d\n",pop(s));
                show(s);
                break;
            }
            case 3: {
                printf("PEEK->%d\n",peek(s));show(s);
                break;
            }
            case 4: {
                printf("%s\n", isEmpty(s) ? "stack EMPTY" : "stack NOT EMPTY");
                break;
            }
            case 5: {
                deleteStack(s);
                s= initStack();
                break;
            }
            case 6: {
                if (isFull( s)){
                    printf("Stack is FULL\n");
                }
                else{
                    printf("Stack is NOT FULL\n");
                }
                break;
            }
            case 9: {
                show(s);
                break;
            }
            default:
                printf("Please choose a correct option!");
        }
    }while (choice!=0);

    // Don't forget to free the memory!
    deleteStack(s);
}
