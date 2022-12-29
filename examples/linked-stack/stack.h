#ifndef PILHA_H
#define PILHA_H

typedef struct stack_ STACK;
typedef struct node_st NODE;

int deleteStack(STACK *stack);
void deleteTopStack(STACK *stack);
int popStack(STACK* stack);
int topStack(STACK* stack);
int pushStack(STACK* stack, int *value);
int sizeStack(STACK* stack);
int fullStack(STACK* stack);
int voidStack(STACK* stack);
STACK* createStack();

#endif //PILHA_H
