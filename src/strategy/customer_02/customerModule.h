// customer_02 customerModule.h

#ifndef CUSTOMERMODULE_H
#define CUSTOMERMODULE_H

#define DIM 50


typedef struct Customer {
    char name[DIM]; //
    char *typeOfCustomer; // gold, silver, bronze, etc

    /* Bind the strategy to Customer using pointers to functions */
    float (*p_priceStrategy)(float amount, float shipping);

    void (*p_greetingsStrategy)();


    // to implement:
    //      List orders; address; telephone number; etc
    //      ...
} T_customer;


void newCustomer(T_customer *p_c);

float computePrice(T_customer c, float totalAmount, float shipping);

void greetings(T_customer c);

#endif //CUSTOMERMODULE_H
