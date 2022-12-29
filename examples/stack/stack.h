#ifndef PILHA_H
#define PILHA_H

typedef struct stack_ STACK;
#define TAM 100

int deleteStack(STACK **stack);
int popStack(STACK* stack);
int topStack(STACK* stack);
int pushStack(STACK* stack, int value);
int sizeStack(STACK* stack);
int fullStack(STACK* stack);
int voidStack(STACK* stack);
STACK* createStack();

#endif //PILHA_H
