// salesPeriod module.h


#include "module.h"


float normalPriceStrategy(int n_item, float unit_cost){
    float shipping_costs = 10;
    return n_item * unit_cost + shipping_costs;
}

float normalRegistrationFeeStrategy(){
    float fee_value = 5;
    return fee_value;
}

SalesStruct createNormalStrategy(){
    SalesStruct s;
    s.p_price = normalPriceStrategy;
    s.p_registration = normalRegistrationFeeStrategy;
    s.number=0;
    strcpy(s.description, "Normal Strategy");
    return s;
}