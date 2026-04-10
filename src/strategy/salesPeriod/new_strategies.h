// salesPeriod new_strategies.h


#ifndef NEW_STRATEGIES_H
#define NEW_STRATEGIES_H
#include "module.h"

/* While some guidelines suggest including header files only in .c files,
 * it's  important to ensure that every header file is self-contained.
 * new_strategy.h  should include module.h
 * because it needs SalesStruct
 *
 * */
float blackPriceStrategy(int n_item, float unit_cost);
float blackRegistrationFeeStrategy();

SalesStruct createBlackStrategy();
#endif //NEW_STRATEGIES_H
