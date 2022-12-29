#ifndef BINARY_TREE
#define BINARY_TREE

#define LEFT_CHILD 0
#define RIGHT_CHILD 1
#include "item/item.h" 

typedef struct binary_tree_t BINARYTREE;

BINARYTREE* binarytree_create(); 
void binarytree_pre_order(BINARYTREE* binaryTree);
void binarytree_in_order(BINARYTREE* binaryTree);
void binarytree_post_order(BINARYTREE* binaryTree);
NODE* recursive_insert_node(NODE* root, ITEM* item, int side, int key);
int binarytree_depth(NODE* node);


#endif // !BINARY_TREE
