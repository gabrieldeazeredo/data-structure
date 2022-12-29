#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct rational_ RATIONAL;

RATIONAL* createR(int numerator, int denominator);
RATIONAL* sumR(RATIONAL *num1, RATIONAL *num2);
RATIONAL* multiplyR(RATIONAL *num1, RATIONAL *num2);
void printR(RATIONAL *rational);
void removeR(RATIONAL *rational);

#endif //RATIONAL_H
