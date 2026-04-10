// customer_01 customerModule.c

#include "customerModule.h"
#include <stdio.h>
#include <string.h> // strcmp()
#include <stdlib.h> // exit()


// 'private' functions

float goldPriceStrategy(float amount, float shipping);

float silverPriceStrategy(float amount, float shipping);

float bronzePriceStrategy(float amount, float shipping);

// implementation

void newCustomer(T_customer *p_c) {

    printf("Insert customer's name: ");
    fgets(p_c->name, DIM, stdin);

    printf("Choose customer type:\n");
    printf("a: GOLD\n");
    printf("b: SILVER\n");
    printf("c: BRONZE\n");

    switch (getchar()) {
        case 'a':
            p_c->typeOfCustomer = "gold";
            // equivalent to (*p_c).typeOfCustomer=...
            break;
        case 'b':
            p_c->typeOfCustomer = "silver";
            break;
        case 'c':
            p_c->typeOfCustomer = "bronze";
            break;
        default:
            perror("Unknown customer type");
            exit(1);
    }

}


float computePrice(T_customer c, float totalAmount, float shipping) {
    /* Calculate the total price
     * depending on customer category. */
    float price;


    if (strcmp(c.typeOfCustomer, "gold") == 0) {
        price = goldPriceStrategy(totalAmount, shipping);

    } else if (strcmp(c.typeOfCustomer, "silver") == 0) {

        price = silverPriceStrategy(totalAmount, shipping);

    } else if (strcmp(c.typeOfCustomer, "bronze") == 0) {
        price = bronzePriceStrategy(totalAmount, shipping);
    } else {
        perror("Unknown customer type");
        exit(1);
    }
    return price;
}


void greetings(T_customer c) {
    /* Happy Birthday (and gift card for some categories) */
    if (strcmp(c.typeOfCustomer, "bronze") == 0) {
        printf("Happy Birthday!");
    } else if (strcmp(c.typeOfCustomer, "silver") == 0) {
        printf("Happy Birthday + gift card 10 euros!");
    } else if (strcmp(c.typeOfCustomer, "gold") == 0) {
        printf("Happy Birthday + gift card 20 euros!");
    } else {
        perror("Unknown customer type");
        exit(1);
    }
}



// PRIVATE

float goldPriceStrategy(float amount, float shipping) {
    float priceDiscount = 0.8;
    return priceDiscount * amount; // free shipping;
}


float silverPriceStrategy(float amount, float shipping) {
    float priceDiscount = 0.9;
    return priceDiscount * amount + shipping;
}

float bronzePriceStrategy(float amount, float shipping) {

    return amount + shipping;
}