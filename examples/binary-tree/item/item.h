#ifndef ITEM_H
#define ITEM_H

#define ERRO -32000
#include "../util/util.h"
typedef struct item_st ITEM;

ITEM *item_criar (int chave, const char *nome, float valor);
boolean item_apagar(ITEM **item);
void item_imprimir(const ITEM *item);
int item_get_key(const ITEM *item);
boolean item_set_chave(ITEM *item, int chave);
char* item_get_name(ITEM *item);

#endif //ITEM_H
