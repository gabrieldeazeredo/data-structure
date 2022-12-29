#include <stdlib.h>
#include "stack.h"

struct node_st
{
    int* value;
    NODE* prequel;
};

struct stack_
{
    NODE* top;
    int size;
};

STACK* createStack()
{
    STACK* stack = (STACK*) malloc(sizeof(STACK));
    
    if(stack != NULL)
    {

        stack->top = NULL;
        stack->size = 0;
    }

    return stack;
}

int voidStack(STACK* stack)
{
    return stack->size == 0;
}

int fullStack(STACK* stack)
{
    return 0;
}

int sizeStack(STACK* stack)
{
    return stack->size;
}

int pushStack(STACK* stack, int *value)
{
    if(stack != NULL)
    {
        NODE* newNode = (NODE*) malloc(sizeof(NODE));
        newNode->value = value;
        newNode->prequel = stack->top;
        stack->top = newNode;
        stack->size++;
        return 1;
    }

    return 0;

}

int topStack(STACK* stack)
{
    return *(stack->top->value);
}

int popStack(STACK* stack)
{
    NODE* popTop = stack->top;
    int *value = stack->top->value;
    stack->top = stack->top->prequel;
    popTop->prequel = NULL;
    free(popTop);
    popTop = NULL;
    stack->size--;
    return *value;    
}

