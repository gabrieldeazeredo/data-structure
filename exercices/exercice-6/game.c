#include "game.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct game_t
{
    char *name;
    char *company;
    int release_year;
};

GAME* game_create(char *name, char *company, int release_year)
{
    GAME* game = (GAME*) malloc(sizeof(GAME));

    game->name = (char*) malloc(sizeof(char)*strlen(name)+1);
    game->company = (char*) malloc(sizeof(char)*strlen(company)+1);

    strcpy(game->name, name);    
    strcpy(game->company, company);

    game->release_year = release_year;

    return game;
}

char* game_get_name(GAME* game)
{
    return game->name;
}

int game_get_release_year(GAME* game)
{
    return game->release_year;    
}

boolean game_is_greater(GAME* game_a, GAME* game_b)
{
    if (game_get_release_year(game_a) > game_get_release_year(game_b))
    {
        return TRUE;
    }
    else if (game_get_release_year(game_a) == game_get_release_year(game_b))
    {
        if (strcmp(game_get_name(game_a), game_get_name(game_b)) > 0)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }  
    }
    else
    {
        return FALSE;
    }
}

boolean game_is_smaller(GAME* game_a, GAME* game_b)
{
    return game_is_greater(game_b, game_a);
}

void game_delete(GAME* game)
{
    if (game != NULL)
    {
        free(game->name);
        free(game->company);

        game->name = NULL;
        game->company = NULL;

        free(game);
        game = NULL;
    } 
}