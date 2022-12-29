#include "avltree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void delete_tree(NODE **node);

static NODE* avl_create_node(GAME* game);
static int get_node_height(NODE* node);

static void recursive_pre_order(NODE* node);
static void recursive_in_order(NODE* node);
static void recursive_post_order(NODE* node);

static NODE* recursive_insert_node(NODE* node, GAME* game);
static NODE* insert_node_and_rotate(NODE* node, GAME* game);

static NODE* recursive_remove_node(NODE** node, int release_year);
static void balanced_binary_tree_remove(NODE** node);
static void change_max_left(NODE* change, NODE* node, NODE* previous);
static boolean avl_tree_remove_game(AVLTREE* avl_tree, int release_year);

static NODE* avl_tree_right_rotate(NODE* node_a);
static NODE* avl_tree_left_rotate(NODE* node_a);
static NODE* avl_tree_right_left_rotate(NODE* node_a);
static NODE* avl_tree_left_right_rotate(NODE* node_a);
static NODE* check_unbalance_and_rotate(NODE* node);

struct avltree_t
{
    NODE* root;
    int depth;
};

struct node_t
{
    int height;
    GAME* game;
    NODE* right;
    NODE* left;
};

/*
 *  Funções para criação e deleção de árvores.
 */

AVLTREE* avl_tree_create()
{
    AVLTREE* avl_tree = (AVLTREE*) malloc(sizeof(AVLTREE));

    if (avl_tree != NULL)
    {
        avl_tree->root = NULL;
        avl_tree->depth = -1;
    }
    
    return avl_tree;
}

void avl_tree_delete(AVLTREE **avl_tree) 
{
    delete_tree(&(*avl_tree)->root);

    free(*avl_tree);
    *avl_tree = NULL;
}

static void delete_tree(NODE **node) 
{
    if (*node != NULL) 
    {
        delete_tree(&(*node)->left);
        delete_tree(&(*node)->right);

        game_delete((*node)->game);

        free(*node);
        *node = NULL;
    }
}

/*
 *  Funções para criação e obtenção da altura de nodes.
 */

static NODE* avl_create_node(GAME* game)
{
    NODE* node = (NODE*) malloc(sizeof(NODE));

    if (node != NULL)
    {
        node->height = 0;
        node->right = NULL;
        node->left = NULL;
        node->game = game;
    }

    return node;
}

static int get_node_height(NODE* node)
{
    if (node == NULL)
    {
        return -1;
    }
    else
    {
        return node->height;
    }
}

/*
 *  Funções para printar a árvore.
 */

void avl_tree_pre_order(AVLTREE* avl_tree)
{
    recursive_pre_order(avl_tree->root);
}

static void recursive_pre_order(NODE* node)
{
    if (node != NULL)
    {
        printf("%s\n", game_get_name(node->game));

        recursive_pre_order(node->left);
        recursive_pre_order(node->right);
    }
}

void avl_tree_in_order(AVLTREE* avl_tree)
{
    recursive_in_order(avl_tree->root);
}

static void recursive_in_order(NODE* node)
{
    if (node != NULL)
    {
        recursive_in_order(node->left);

        printf("%s\n", game_get_name(node->game));

        recursive_in_order(node->right);
    }
}

void avl_tree_post_order(AVLTREE* avl_tree)
{
    recursive_post_order(avl_tree->root);
}

static void recursive_post_order(NODE* node)
{
    if (node != NULL)
    {
        recursive_post_order(node->left);
        recursive_post_order(node->right);

        printf("%s\n", game_get_name(node->game));
    }
}

/*
 *  Funções para rotações AVL.
 */

static NODE* avl_tree_right_rotate(NODE* node_a)
{
    NODE* node_b = node_a->left;
    
    node_a->left = node_b->right;
    node_b->right = node_a;

    node_a->height = max(get_node_height(node_a->left),
                         get_node_height(node_a->right)) + 1;
    
    node_b->height = max(get_node_height(node_b->left),
                         node_a->height) + 1;

    return node_b;
}

static NODE* avl_tree_left_rotate(NODE* node_a)
{
    NODE* node_b = node_a->right;
    
    node_a->right = node_b->left;
    node_b->left = node_a;

    node_a->height = max(get_node_height(node_a->left),
                         get_node_height(node_a->right)) + 1;
    
    node_b->height = max(get_node_height(node_b->right),
                         node_a->height) + 1;

    return node_b;
}

static NODE* avl_tree_left_right_rotate(NODE* node_a)
{
    node_a->left = avl_tree_left_rotate(node_a->left);

    return avl_tree_right_rotate(node_a);
}

static NODE* avl_tree_right_left_rotate(NODE* node_a)
{
    node_a->right = avl_tree_right_rotate(node_a->right);

    return avl_tree_left_rotate(node_a);
}

static NODE* check_unbalance_and_rotate(NODE* node)
{
    if (node != NULL)
    {
        node->height = max(get_node_height(node->left), 
                                get_node_height(node->right))+1;
        
        if (get_node_height(node->left) - get_node_height(node->right) == -2)
        {

            if (get_node_height(node->right->left) - get_node_height(node->right->right) <= 0)
            {
                node = avl_tree_left_rotate(node);
            }
            else
            {
                node = avl_tree_right_left_rotate(node);
            }
            
        }
        
        if (get_node_height(node->left) - get_node_height(node->right) == 2)
        {

            if (get_node_height(node->left->left) - get_node_height(node->left->right) >= 0)
            {
                node = avl_tree_right_rotate(node);
            }
            else
            {
                node = avl_tree_left_right_rotate(node);
            }   
        }  

        return node;    
    }
    else
    {
        return NULL;
    }  
}

/*
 *  Funções para inserção de jogos na árvore.
 */

void avl_tree_insert_game(AVLTREE* avl_tree, GAME* game)
{
    avl_tree->root = insert_node_and_rotate(avl_tree->root, game);
}

static NODE* recursive_insert_node(NODE* node, GAME* game)
{
    if (node == NULL)
    {
        node = avl_create_node(game);
    }
    else if (game_is_greater(game, node->game))
    {
        node->right = insert_node_and_rotate(node->right, game);
    }
    else if (game_is_smaller(game, node->game)) 
    {
        node->left = insert_node_and_rotate(node->left, game);
    }
    
    return node;
}

static NODE* insert_node_and_rotate(NODE* node, GAME* game)
{
    node = recursive_insert_node(node, game);

    node->height = max(get_node_height(node->left),
                        get_node_height(node->right)) + 1;

    node = check_unbalance_and_rotate(node);

    return node;
}

/*
 *  Funções para remoção de jogos na árvore.
 */

void avl_tree_remove_games(AVLTREE* avl_tree, int release_year)
{
    while (avl_tree_remove_game(avl_tree, release_year) == TRUE)
    {
        avl_tree_remove_game(avl_tree, release_year);
    }
}

static boolean avl_tree_remove_game(AVLTREE* avl_tree, int release_year)
{
    return recursive_remove_node(&avl_tree->root, release_year) != NULL;
}

static NODE* recursive_remove_node(NODE** node, int release_year)
{
    if (*node != NULL)
    {
        if (release_year == game_get_release_year((*node)->game))
        {
            balanced_binary_tree_remove(node);
        }
        else
        {
            *node = check_unbalance_and_rotate(*node);

            if (release_year > game_get_release_year((*node)->game))
            {
                return recursive_remove_node(&(*node)->right, release_year);
            }
            else
            {
                return recursive_remove_node(&(*node)->left, release_year);
            }    
        }
        
        if (*node == NULL)
        {
            return NULL;
        }
        else
        {
            *node = check_unbalance_and_rotate(*node);
            return *node;
        }
    }
    else
    {
        return NULL;
    }
}

static void balanced_binary_tree_remove(NODE** node)
{
    NODE* remove_node;

    if ((*node)->right == NULL || (*node)->left == NULL)
    {
        remove_node = *node;

        if ((*node)->left == NULL)
        {
            *node = (*node)->right;
        }
        else
        {
            *node = (*node)->left;
        }

        game_delete(remove_node->game);

        free(remove_node);

        remove_node = NULL;
    }
    else
    {
        change_max_left((*node)->left, (*node), (*node));
    } 
}

static void change_max_left(NODE* change, NODE* node, NODE* previous)
{
    if (change->right != NULL)
    {
        change_max_left(change->right, node, change);
        return;
    }

    if (node == previous)
    {
        previous->left = change->left;
    }
    else
    {
        previous->right = change->left;
    }
    
    game_delete(node->game);
    node->game = change->game;

    free(change);
    change = NULL;
}  