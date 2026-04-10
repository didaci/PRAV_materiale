
#ifndef CUSTOMERMODULE_H
#define CUSTOMERMODULE_H

#define DIM 50


typedef struct Customer {
    char name[DIM]; //
    char *typeOfCustomer; // gold, silver, bronze, etc
    // pessima scelta, solo per uso didattico
    // (mostrare 'che si può fare' e quali sono i limiti)
    // ma meglio usare enum o int

    // to implement:
    //      List orders; address; telephone number; etc
    //      ...
} T_customer;


void newCustomer(T_customer *p_c);

float computePrice(T_customer c, float totalAmount, float shipping);
void greetings(T_customer c);
// passare la struttura a computePrice e greetings
// è una scelta inefficiente - meglio passare il puntatore -
// ma qui voglio mettere il focus su altri aspetti

#endif //CUSTOMERMODULE_H
