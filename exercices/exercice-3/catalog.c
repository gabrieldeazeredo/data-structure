#include "catalog.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"

struct game_
{
    char *name;
    char *company;
    int releaseYear;
};

struct catalog_
{
    GAME **game;
    int gamesAmount;
};

CATALOG* catalogCreate()
{
    CATALOG *catalog = (CATALOG*) malloc(sizeof(CATALOG));
    catalog->game = NULL;
    catalog->gamesAmount = 0;
    return catalog;
}

void sighUpGame(int count, CATALOG *catalog, char *name, char *company, int releaseYear)
{
    
    GAME *game = (GAME*) malloc(sizeof(GAME));
    game->name = (char*) malloc(sizeof(char)*(*name));
    game->company = (char*) malloc(sizeof(char)*(*company));
    strcpy(game->name, name);    
    strcpy(game->company, company);
    game->releaseYear = releaseYear;
    
    addGame(count, catalog, game);
}

void addGame (int count, CATALOG *catalog, GAME *game)
{
    catalog->game = (GAME**) realloc(catalog->game, count*sizeof(GAME**));

    catalog->game[count-1] = game;
    catalog->gamesAmount++;

}


void searchByYear(CATALOG *catalog, int year)
{
    int boolGame = 0;

    for(int i = 0; i<catalog->gamesAmount; i++)
    {
        if(catalog->game[i]->releaseYear == year){
            boolGame = 1;      
            printf("%s \n", catalog->game[i]->name);
        }
    }
    
    if(boolGame == 0)
    {
        printf("Nada encontrado \n");
    }
}

void searchByCompany(CATALOG *catalog, char *company)
{

    int boolGame = 0;

    for(int i = 0; i<catalog->gamesAmount; i++)
    {
        if(strcmp(catalog->game[i]->company,company) == 0){
            boolGame = 1;      
            printf("%s \n", catalog->game[i]->name);
        }
    }
    
    if(boolGame == 0)
    {
        printf("Nada encontrado \n");
    }

}

void deleteCatalog(CATALOG* catalog)
{
    for(int i = 0; i<catalog->gamesAmount; i++)
    {
        free(catalog->game[i]->name);
        free(catalog->game[i]->company);
        free(catalog->game[i]);
    }
    free(catalog->game);
    free(catalog);

}
