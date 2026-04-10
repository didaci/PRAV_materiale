/* * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Ask for customer's name, type (gold, silver, bronze)
 * (and, optionally, for other data)
 *
 * Apply a discount that depends on the type of customer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * */


/*
 * Questa implementazione contiene molti difetti
 * - mischia fgets, getchar, scanf
 * - gestione fragile dell'input
 * - ...
 * ma qui ci stiamo focalizzando su altri concetti,
 * accettiamo queste imprecisioni
 *
 */
#include <stdio.h>
#include "customerModule.h"


int main() {
    T_customer c;
    float price, finalPrice;
    const float shipping = 10;


    printf("** INSERT CUSTOMER **\n");
    newCustomer(&c);

    printf("INSERT PRICE:\n");
    scanf("%f", &price);
    printf("COMPUTE FINAL PRICE (discount, shipping, etc):\n");

    finalPrice = computePrice(c, price, shipping);
    //finalPrice=computePrice(p_c->typeOfCustomer,price, shipping);

    // OUTPUT

    printf("customer:\n");
    printf("%s -> %s customer \n", c.name, c.typeOfCustomer);

    printf("Initial price: %.2f\n", price);
    printf("Final price: %.2f\n", finalPrice);

    greetings(c);

    return 0;
}
