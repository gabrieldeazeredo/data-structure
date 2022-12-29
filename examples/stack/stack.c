#include <stdlib.h>
#include "stack.h"

struct stack_
{
    int values[TAM];
    int top;
};

STACK* createStack()
{
    STACK* stack = (STACK*) malloc(sizeof(STACK));
    
    if(stack != NULL)
    {

        stack->top = 0;
    }

    return stack;
}

int voidStack(STACK* stack)
{
   
    return stack->top == 0;

}

int fullStack(STACK* stack)
{
    
    return stack->top == TAM;
    
}

int sizeStack(STACK* stack)
{
    
    return stack->top;
}

int pushStack(STACK* stack, int value)
{
    if((stack != NULL)&&(!fullStack(stack)))
    {
        stack->values[stack->top] = value;
        stack->top++;
        return 1;
    }

    return 0;

}

int topStack(STACK* stack)
{

        return stack->values[stack->top-1];
}

int popStack(STACK* stack)
{
    int* topValue;
    topValue = &(stack->values[stack->top]);
    stack->values[stack->top-1] = 0;
    stack->top--;
    return *topValue;
    
}

int deleteStack(STACK **stack)
{
    if(stack != NULL)
    {
        free(*stack);
        *stack = NULL;
        return 1;
    }
    
    return 0;
}
