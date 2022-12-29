#include "client-tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static NODE* create_new_node(CLIENT* client);
static NODE* recursive_insert_node(NODE* node, CLIENT* client);
static CLIENT* recursive_search_client(NODE* node, char* client_cpf);
static void recursive_pre_order(NODE* node);
static void recursive_remove_client(NODE** node, char* client_cpf);
static void change_min_right(NODE* change, NODE* node, NODE* previous);
static void delete_tree(NODE** node);

struct client_tree_t
{
    NODE* root;
};

struct node_t
{
    CLIENT* client;
    NODE* right;
    NODE* left;
};

CLIENT_TREE* client_tree_create()
{
    CLIENT_TREE* client_tree = (CLIENT_TREE*) malloc(sizeof(CLIENT_TREE));
    client_tree->root = NULL;

    return client_tree;
}

void client_tree_delete_tree(CLIENT_TREE **client_tree) {
    delete_tree(&(*client_tree)->root);
    free(*client_tree);
    *client_tree = NULL;
}

void delete_tree(NODE **node) {
    if (*node != NULL) {
        delete_tree(&(*node)->left);
        delete_tree(&(*node)->right);
        client_remove((*node)->client);
        free(*node);
        *node = NULL;
    }
}

void client_tree_insert_client(CLIENT_TREE* client_tree, CLIENT* client)
{
    client_tree->root = recursive_insert_node(client_tree->root, client);
}

NODE* create_new_node(CLIENT* client)
{
    NODE* new_node = (NODE*) malloc(sizeof(NODE));
    
    new_node->client = client;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

NODE* recursive_insert_node(NODE* node, CLIENT* client)
{
    if (node == NULL)
    {
        node = create_new_node(client);
    }
    else if (cpf_greater_than(client_get_cpf(client), client_get_cpf(node->client)))
    {
        node->right = recursive_insert_node(node->right, client);
    }
    else if (cpf_greater_than(client_get_cpf(node->client), client_get_cpf(client)))
    {
        node->left = recursive_insert_node(node->left, client);
    }

    return node;
}

CLIENT* client_tree_search_client(CLIENT_TREE* client_tree, char* client_cpf)
{
    return recursive_search_client(client_tree->root, client_cpf);
}

CLIENT* recursive_search_client(NODE* node, char* client_cpf)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (cpf_is_equal(client_get_cpf(node->client), client_cpf))
    {
        return node->client;
    }
    else if (cpf_greater_than(client_cpf, client_get_cpf(node->client)))
    {
        return recursive_search_client(node->right, client_cpf);
    }
    else if (cpf_greater_than(client_get_cpf(node->client), client_cpf))
    {
        return recursive_search_client(node->left, client_cpf);
    }

    return NULL;
} 

void client_tree_pre_order(CLIENT_TREE* client_tree)
{
    recursive_pre_order(client_tree->root);
}

void recursive_pre_order(NODE* node)
{
    if (node != NULL)
    {
        cpf_numbers_print(client_get_cpf(node->client));
        recursive_pre_order(node->left);
        recursive_pre_order(node->right);
    }
}

void client_tree_remove_client(CLIENT_TREE* client_tree, char* client_cpf)
{
    recursive_remove_client(&client_tree->root, client_cpf);
}

void recursive_remove_client(NODE** node, char* client_cpf)
{
    NODE* removeNode;

    if (*node != NULL)
    {
        if (cpf_is_equal(client_cpf, client_get_cpf((*node)->client)))
        {
            if ((*node)->right == NULL || (*node)->left == NULL)
            {
                removeNode = *node;
                if ((*node)->left == NULL)
                {
                    *node = (*node)->right;
                }
                else
                {
                    *node = (*node)->left;
                }
                free(removeNode);
                removeNode = NULL;
            }
            else
            {
                change_min_right((*node)->right, (*node), (*node));
            }
        }   
    }
} 

void change_min_right(NODE* change, NODE* node, NODE* previous)
{
    if (change->left != NULL)
    {
        change_min_right(change->left, node, change);
        return;
    }
    if (node == previous)
    {
        previous->right = change->right;
    }
    else
    {
        previous->left = change->right;
    }
    client_print_info(node->client);
    client_remove(node->client);
    node->client = change->client;
    free(change);
    change = NULL;
}
