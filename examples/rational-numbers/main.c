#include <stdio.h>
#include "Rational/rational.h"

int main()
{    
    RATIONAL *rational1 = createR(5, 3);
    RATIONAL *rational2 = createR(2, 4);

    RATIONAL *sum = sumR(rational1, rational2);
    RATIONAL *prod = multiplyR(rational1, rational2);

    printR(sum);
    printR(prod);

    removeR(rational1);
    removeR(rational2);
    removeR(sum);
    removeR(prod);

    return 0;
}







