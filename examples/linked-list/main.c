#include "list.h"
#include <stdio.h>

int main()
{
    LIST *list = list_create();

    ITEM *item1 =  item_criar(1, "exodia", 32.1);
    ITEM *item2 =  item_criar(2, "caio", 12.1);
    ITEM *item3 =  item_criar(3, "sophia", 999.9);

    list_append(list, item1);
    list_append(list, item2);

    list_insert_position(list, 0, item3);

    list_print(list);    
    list_delete(&list);
    
    return 0;
}
