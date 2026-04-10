// salesPeriod main.c


#include <stdio.h>
#include "module.h"
#include "new_strategies.h"
int main() {
    float registration_price, total_price;
    SalesStruct actual_strategy;

    actual_strategy = createNormalStrategy();
    //actual_strategy = createBlackStrategy();

    registration_price = actual_strategy.p_registration();
    total_price = actual_strategy.p_price(10, 20);

    printf("I am using %s\n", actual_strategy.description);
    printf("Total price =%.2f, registration = %.2f", total_price, registration_price );
}