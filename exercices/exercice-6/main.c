#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "game.h"
#include "avltree.h"

static void insert_data_into_tree(AVLTREE* avl_tree);
static GAME* create_game_from_line(char* line);

int main(int argc, char const *argv[])
{
    AVLTREE* game_avl_tree = avl_tree_create();

    insert_data_into_tree(game_avl_tree);

    int n = 0;
    scanf("%d", &n); 
    extra_line_end(); 

    char* input = NULL;
    
    input = read_line();

    while (strcmp(input, "F"))
    {
        avl_tree_remove_games(game_avl_tree, atoi(input));

        free(input);
        input = read_line();
    } 

    free(input);
    
    switch(n)
    {
        case 1:
            avl_tree_pre_order(game_avl_tree);
            break;
        
        case 2:
            avl_tree_in_order(game_avl_tree);
            break;

        case 3:
            avl_tree_post_order(game_avl_tree);
            break;
    }

    avl_tree_delete(&game_avl_tree);

    return 0;
} 

static void insert_data_into_tree(AVLTREE* avl_tree)
{
    FILE *filePointer = fopen("CSV.csv", "r");
    char* line = NULL;

    if (filePointer != NULL)
    {
        fseek(filePointer, 3, SEEK_SET);

        while (!feof(filePointer))
        {
            line = file_read_line(filePointer);
            
            if (line != NULL)
            {                        
                GAME* game = create_game_from_line(line);

                avl_tree_insert_game(avl_tree, game);

                free(line);
                line = NULL;
            }        
        }

        fclose(filePointer);
    }    
}

static GAME* create_game_from_line(char* line)
{
    char* token = NULL;
    char* name = NULL;
    char* company = NULL;
    int realease_year = 0;

    token = strtok(line, ";");
    name = token;

    token = strtok(NULL, ";");
    realease_year = atoi(token);

    token = strtok(NULL, ";");
    company = token;

    GAME* game = game_create(name, company, realease_year);

    return game;
}  