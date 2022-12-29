#include "binary-tree.h"
#include <stdlib.h>

typedef struct node_t NODE;


static void recursive_binarytree_pre_order(NODE* root);
static void recursive_in_order(NODE* root);
static void recursive_post_order(NODE* root);
static NODE* create_node(ITEM* item);

struct binary_tree_t 
{
    NODE* root;
    int depth;   
};

struct node_t
{
    ITEM* item;
    NODE* right;
    NODE* left;
};

BINARYTREE* binarytree_create()
{
    BINARYTREE* binaryTree = (BINARYTREE*) malloc(sizeof(BINARYTREE));

    if (binaryTree != NULL)
    {
        binaryTree->root = NULL;
        binaryTree->depth = -1;
    }
    
    return binaryTree;
}

void binarytree_pre_order(BINARYTREE* binaryTree)
{
    recursive_pre_order(binaryTree);
}

void recursive_pre_order(NODE* root)
{
    if (root != NULL)
    {
        item_imprimir(root->item);
        binarytree_pre_order(root->left);
        binarytree_pre_order(root->right);
    }
}

void binarytree_in_order(BINARYTREE* binaryTree)
{
    recursive_in_order(binaryTree);
}

void recursive_in_order(NODE* root)
{
    if (root != NULL)
    {
        binarytree_pre_order(root->left);
        item_imprimir(root->item);
        binarytree_pre_order(root->right);
    }
}

void binarytree_post_order(BINARYTREE* binaryTree)
{
    recursive_post_order(binaryTree);
}

void recursive_post_order(NODE* root)
{
    if (root != NULL)
    {
        binarytree_pre_order(root->left);
        binarytree_pre_order(root->right);
        item_imprimir(root->item);
    }
}

boolean binarytree_insert(BINARYTREE* binaryTree, ITEM* item)
{

    if (binaryTree->root = recursive_insert_node(binaryTree->root, item) != NULL)
    {
        binaryTree->depth++;
        return FALSE;
    }   

}

ITEM* binarytree_search(BINARYTREE* binaryTree, int key)
{
    return(recursive_search(binaryTree->root, key));
}

ITEM* recursive_search(NODE* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (item_get_key(root->item) == key)
    {
        return root->item;
    }
    else if (item_get_key(root->item) < key)
    {
        recursive_search(root->right, key);
    }
    else if (item_get_key(root->item) > key)
    {
        recursive_search(root->left, key);
    }
    
    
}

NODE* recursive_insert_node(NODE* root, ITEM* item){

    if (root == NULL)
    {
        root = create_node(item);
    }
    else if (item_get_key(item) > item_get_key(root->item))
    {
        root->right = recursive_insert_node(root->right, item);
    }
    else if (item_get_key(item) < item_get_key(root->item))
    {
        root->left = recursive_insert_node(root->left, item);
    }

    return root;
}

NODE* create_node(ITEM* item)
{
    NODE* newNode = (NODE*) malloc(sizeof(NODE));

    if (newNode != NULL)
    {
        newNode->item = item;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    
    return newNode;
}

int binarytree_depth(NODE* node)
{
    if (node != NULL)
    {
        return -1;
    }
    
    int left = binarytree_depth(node->left);
    int right = binarytree_depth(node->right);

    if (left > right)
    {
       return left + 1; 
    }
    else
    {
        return right + 1;
    }
}
