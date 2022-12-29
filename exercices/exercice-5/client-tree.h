#ifndef CLIENTTREE_H
#define CLIENTTREE_H

#include "client.h"

typedef struct client_tree_t CLIENT_TREE;
typedef struct node_t NODE;

CLIENT_TREE* client_tree_create();

void client_tree_insert_client(CLIENT_TREE* client_tree, CLIENT* client);
CLIENT* client_tree_search_client(CLIENT_TREE* client_tree, char* client_cpf);
void client_tree_pre_order(CLIENT_TREE* client_tree);
void client_tree_remove_client(CLIENT_TREE* client_tree, char* client_cpf);

void client_tree_delete_tree(CLIENT_TREE **client_tree);

#endif // CLIENTTREE_H