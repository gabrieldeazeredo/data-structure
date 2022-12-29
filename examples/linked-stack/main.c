#include <stdio.h>
#include "stack.h"


int main()
{
    int *a, *b, *c;
    *a = 3;
    *b = 4;
    *c = 10;
    STACK *stack;
    stack = createStack();
    pushStack(stack, a);
    pushStack(stack, b);
    printf("%d \n", topStack(stack));
    return 0;
}
