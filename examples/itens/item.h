#ifndef ITEM_H
#define ITEM_H


#define TRUE 1
#define FALSE 0

#define boolean int

typedef struct item_st ITEM;

ITEM *item_criar(int chave, char *nome, float valor);
boolean int_apagar(ITEM **item);
void item_imprimir(ITEM *item);
int item_get_chave(ITEM *item);
boolean item_set_chave(ITEM **item, int chave);




#endif //ITEM_H
