// salesPeriod module.h


#ifndef MODULE_H
#define MODULE_H
#include <string.h>
// Define function pointer types
typedef float (*PriceFunction)(int n_item, float unit_cost);
typedef float (*RegistrationFunction)(void);

// Define the struct using typedef
typedef struct {
    PriceFunction p_price;
    RegistrationFunction p_registration;
    char description[100];
    int number;
} SalesStruct;

SalesStruct createNormalStrategy();
float normalPriceStrategy(int n_item, float unit_cost);
float normalRegistrationFeeStrategy();


#endif
