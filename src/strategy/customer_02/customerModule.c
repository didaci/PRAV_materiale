// customer_02 customerModule.c

#include "customerModule.h"
#include <stdio.h>
#include <string.h> // strcmp()
#include <stdlib.h> // exit()


// 'private' functions

float goldPriceStrategy(float amount, float shipping);

float silverPriceStrategy(float amount, float shipping);

float bronzePriceStrategy(float amount, float shipping);

void goldGreetingsStrategy();

void silverGreetingsStrategy();

void bronzeGreetingsStrategy();



// implementation



//******************************************************
//   CREATE CUSTOMER
//******************************************************


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
            p_c->p_priceStrategy = goldPriceStrategy;
            p_c->p_greetingsStrategy = goldGreetingsStrategy;
            break;
        case 'b':
            p_c->typeOfCustomer = "silver";
            p_c->p_priceStrategy = silverPriceStrategy;
            p_c->p_greetingsStrategy = silverGreetingsStrategy;
            break;
        case 'c':
            p_c->typeOfCustomer = "bronze";
            p_c->p_priceStrategy = bronzePriceStrategy;
            p_c->p_greetingsStrategy = bronzeGreetingsStrategy;
            break;
        default:
            perror("Unknown customer type");
            exit(1);
    }

}



//******************************************************
//   PRICE STRATEGY
//******************************************************


float computePrice(T_customer c, float totalAmount, float shipping) {
    /* compute the total price
     * depending on customer category. */
    float price;

    price = (c.p_priceStrategy)(totalAmount, shipping);
    /* it will be
    * bronzePriceStrategy, silverPriceStrategy, goldPriceStrategy
    * or others
    * depending on the Customer*/
    return price;
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


//******************************************************
//   GREETINGS STRATEGY
//******************************************************
void greetings(T_customer c) {
    // Happy Birthday (and gift card for some categories)
    (c.p_greetingsStrategy)();
}

// PRIVATE

void goldGreetingsStrategy() {
    printf("Happy Birthday + gift card 20 euros!");
};

void silverGreetingsStrategy() {
    printf("Happy Birthday + gift card 10 euros!");
};

void bronzeGreetingsStrategy() {
    printf("Happy Birthday!");
};


