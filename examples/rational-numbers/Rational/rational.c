#include "rational.h"
#include <stdlib.h>
#include <stdio.h>

// É uma boa prática deixar "_" depois da declaração do nome da struct
// assim é possível saber que é apenas uma delcaração, que não iremos 
// usar posteriormente. (Usaremos o typedef que da estrutura de dados 
// RATIONAL nesse caso)

struct rational_ 
{
    int numerator;
    int denominator;

};
// Poderíamos ter retornado e salvado o número localmente, mas é mais 
// comum retornar um ponteiro da struct e salvar dinâmicamente para con-
// seguir trabalhar melhor com a memória.

RATIONAL* createR(int numerator, int denominator)
{
    if(denominator == 0){
        return NULL;
    }

    RATIONAL *rational = (RATIONAL*) malloc(sizeof(RATIONAL));
    rational->numerator = numerator;
    rational->denominator = denominator;

    return rational;

}

RATIONAL* sumR(RATIONAL *num1, RATIONAL *num2)
{

    RATIONAL *sum = (RATIONAL*) malloc(sizeof(RATIONAL));
    sum->numerator = num1->numerator * num2->denominator + num2->numerator * num1->denominator;
    sum->denominator = num1->denominator * num2->denominator;
    
    return sum;
}

void printR(RATIONAL *rational)
{
    printf("Racional: %d/%d\n", rational->numerator, rational->denominator);
}

RATIONAL* multiplyR(RATIONAL *num1, RATIONAL *num2)
{
    RATIONAL *product = (RATIONAL*) malloc(sizeof(RATIONAL));
    product->numerator = num1->numerator * num2->numerator;
    product->denominator = num1->denominator*num2->denominator;
    
    return product;
}

void removeR(RATIONAL *rational)
{
    if (rational != NULL)
    {
        free(rational);
    }
}



