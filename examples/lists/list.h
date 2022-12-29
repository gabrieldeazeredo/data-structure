#ifndef LISTA_H
#define LISTA_H

#include "util.h"
#include "item.h"

#define TAM_MAX 100
#define START 0
#define ERROR -3200

typedef struct list_ LIST;

LIST* list_create();
boolean list_append(LIST *list, ITEM *item);
boolean list_insert_position(LIST *list, int pos, ITEM *item);
boolean list_delete(LIST **list);
boolean list_remove(LIST *list);
ITEM *list_sequencial_search(int key, LIST *list);
int list_size(const LIST *list);
boolean list_empty(LIST *list);
boolean list_filled(LIST *list);
void list_print(LIST* list);

#endif //LISTA_H
