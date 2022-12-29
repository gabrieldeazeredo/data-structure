#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct list_ {
    ITEM *values[TAM_MAX];
    int start;
    int end; 
};

static void move_values_to_right(LIST *list, int pos);
static void list_remove_all(LIST *list);

LIST* list_create()
{
    LIST *list = (LIST*) malloc(sizeof(list));    
    
    if(list != NULL){
        list->start = START;
        list->end = list->start;
    }

    return list;
}

boolean list_append(LIST *list, ITEM *item)
{
    if((list != NULL)&& !list_filled(list))
    {
        list->values[list->end] = item;
        list->end++;
        return TRUE;
    }
    return FALSE;
}

boolean list_filled(LIST *list)
{
    if((list->end) == TAM_MAX)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }    
}

boolean list_insert_position(LIST *list, int pos, ITEM *item)
{

    if(!list_filled(list) && (pos < list->end))
    {
        move_values_to_right(list, pos);
        list->values[pos] = item;
        list->end++;
        return TRUE;

    }
    return FALSE;
}

static void move_values_to_right(LIST *list, int pos)
{

    for(int i = list->end; i >= pos; i--)
    {
        list->values[i+1] = list->values[i];       
    }
}

boolean list_delete(LIST **list)
{
    if((*list != NULL) && (!list_empty(*list)))
    {
        list_remove_all(*list);
        free(*list);
        *list = NULL;
        return TRUE;
    }
    return FALSE;
}

static void list_remove_all(LIST *list)
{
    for (int i = 0; i< list->end; i++)
    {
        list->values[i] = NULL;
    }
    list->end = START;
}

boolean list_empty(LIST *list)
{
    if (list->end == 0)
    {
        return TRUE;    
    }
    else
    {
        return FALSE;
    }
}

ITEM *list_sequencial_search(int key, LIST *list)
{
    for (int i=0; i<list->end;i++)
    {
        if (item_get_key(list->values[i]) == key)
        {
            return list->values[i];
        }
    }

    return NULL;
}

ITEM *list_ord_sequencial_search(int key, LIST *list)
{
    for (int i=0; i<list->end;i++)
    {
        if (item_get_key(list->values[i]) == key)
        {
            return list->values[i];
        }
        else if(item_get_key(list->values[i]) > key)
        {
            return NULL;
        }
    }

    return NULL;
}

void list_print(LIST* list)
{

    for(int i = 0; i < list->end; i++) 
    {
        printf("%s \n", item_get_name(list->values[i]));
    }
}
