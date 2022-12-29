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

boolean binarytree_insert(BINARYTREE* binaryTree, ITEM* item, int side, int key)
{
    if (binaryTree->root != NULL)
    {
        return (binaryTree->root = create_node(item) != NULL);
    }
    else
    {
        if (binaryTree->root = recursive_insert_node(binaryTree->root, item, side, key) != NULL)
        {
            binaryTree->depth++;
            return FALSE;
        }   
    }
}


NODE* recursive_insert_node(NODE* root, ITEM* item, 
                            int side, int key){
    if (root != NULL)
    {
        root->left = binarytree_insert_node(root->left, item, side, key);
        root->right = binarytree_insert_node(root->right, item, side, key);

        if (key == item_get_key(root->item))
        {
            if (side == LEFT_CHILD)
            {
                if (root->left == NULL)
                {
                    root->left = create_node(item);
                }
                
            }
            else if (side == RIGHT_CHILD)
            {
                if (root->right == NULL)
                {
                    root->right = binarytree_create_node(item);
                }
            }
        }
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
