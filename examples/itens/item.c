#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct item_st
{
    int chave;
    char nome[20];
    float valor;

};


ITEM *item_criar (int chave, char *nome, float valor)
{

    ITEM *item = (ITEM*) malloc(sizeof(ITEM));

    if(item != NULL)
    {
        item->chave = chave;
        strcpy(item->nome, nome);
        item->valor = valor;
        
        return item;
    }else
        return NULL;
    }

}


boolean item_apagar(ITEM **item)
{
    if (*item != NULL)
    {
        (*item)->chave = -3200;
        free (*item);
        *item = NULL;
        return TRUE;
    }

    return FALSE;
}

int item_get_chave(ITEM *item)
{
    if(item != NULL)
    {
        return item->chave;
    }
    exit(1);

}

boolean item_set_chave(ITEM **item, int chave)
{
    if(*item != NULL)
    {
        (*item)->chave = chave;
        return TRUE;
    }
    return FALSE;
}   
