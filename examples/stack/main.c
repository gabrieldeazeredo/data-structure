#include <stdio.h>
#include "stack.h"


int main()
{
    STACK *stack;
    stack = createStack();
    pushStack(stack, 3);
    printf("%d \n", topStack(stack));
    pushStack(stack, 4);
    printf("%d \n", topStack(stack));
    popStack(stack);
    printf("%d \n", topStack(stack));
    popStack(stack);
    printf("%d \n", voidStack(stack));
    deleteStack(&stack);
    return 0;
}
