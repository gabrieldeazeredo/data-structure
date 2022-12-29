#include "list.h"
#include <stdlib.h>
#include <stdio.h>


struct node_st
{
    ITEM* item;
    NODE* next;

};

struct list_st {
    NODE* start;
    NODE* end;
    int size;
     
};

LIST* list_create()
{
    LIST *list = (LIST*) malloc(sizeof(list));    
    
    if(list != NULL){
        list->start = NULL;
        list->end = NULL;
        list->size = 0;
    
        return list;
    }
    return NULL;
}


boolean list_append(LIST *list, ITEM *item)
{
    if(list != NULL)
    {
        NODE* newNode = (NODE*) malloc(sizeof(NODE));

        newNode->item = item;
        newNode->next = NULL;

        if (list->size == 0)
        {
            list->start = newNode;
        }
        else
        {
            list->end->next = newNode;
        }
        list->end = newNode;
        list->size++;
        
        return TRUE;        
    }
    return FALSE;
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
    if (list->start == 0)
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
