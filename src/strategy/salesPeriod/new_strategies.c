// salesPeriod new_strategies.c

#include "new_strategies.h"
#include "module.h"
float blackPriceStrategy(int n_item, float unit_cost){
    return n_item * unit_cost *0.8;
}
float blackRegistrationFeeStrategy(){
    float fee_value = 0;
    return fee_value;
}


SalesStruct createBlackStrategy(){
    SalesStruct s;
    s.p_price = blackPriceStrategy;
    s.p_registration = blackRegistrationFeeStrategy;
    s.number=1;
    strcpy(s.description, "Black Friday Strategy");
    return s;
}