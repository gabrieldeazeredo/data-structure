#ifndef AVLTREE_H
#define AVLTREE_H

#define max(a, b) ((a > b) ? a  : b)

#include "util.h"
#include "game.h"

typedef struct avltree_t AVLTREE;
typedef struct node_t NODE;

AVLTREE* avl_tree_create();
void avl_tree_delete(AVLTREE **avl_tree);

void avl_tree_insert_game(AVLTREE* avl_tree, GAME* game);
void avl_tree_remove_games(AVLTREE* avl_tree, int realease_year);

void avl_tree_pre_order(AVLTREE* avl_tree);
void avl_tree_in_order(AVLTREE* avl_tree);
void avl_tree_post_order(AVLTREE* avl_tree);

#endif // ALVTREE_H