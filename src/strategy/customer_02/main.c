// customer_02 main.c

/* * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Ask for customer's name, type (gold, silver, bronze)
 * (and, optionally, for other data)
 *
 * Apply a discount that depends on the type of customer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * */

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

    // OUTPUT

    printf("customer:\n");
    printf("%s -> %s customer \n", c.name, c.typeOfCustomer);

    printf("Initial price: %.2f\n", price);
    printf("Final price: %.2f\n", finalPrice);

    greetings(c);

    getchar();
    return 0;
}
