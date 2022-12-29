#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include "util.h"

typedef struct node_ NODE;
typedef struct bigNumber_ BIGNUMBER;

// TO CREATE BIGNUMBERS
BIGNUMBER* bignumber_create(char *input);

// TO PRINT BIGNUMBERS
void bignumber_print(BIGNUMBER* bigNumber);

// TO SUM BIGNUMBERS
BIGNUMBER* bignumber_sum(BIGNUMBER* bigNumber1, BIGNUMBER* bigNumber2);

// TO COMPARE BIGNUMBERS 
boolean bignumber_greater_than(BIGNUMBER* bigNumber1, BIGNUMBER* bigNumber2);
boolean bignumber_abs_greater_than(BIGNUMBER* bigNumber1, BIGNUMBER* bigNumber2);
boolean bignumber_less_than(BIGNUMBER* bigNumber1, BIGNUMBER* bigNumber2);
boolean bignumber_equal(BIGNUMBER* bigNumber1, BIGNUMBER* bigNumber2);

// TO DELETE BIGNUMBERS
void bignumber_delete(BIGNUMBER* bigNumber);

#endif //BIGNUMBER_H
