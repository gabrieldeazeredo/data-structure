#include <stdio.h>
#include <stdlib.h>
#include "pokedex.h"
#include <string.h>

POKEMON** callAddPokemon(POKEMON **pokes, int count);
void callAddAttack(POKEMON **pokes, int indexPokemon, int indexAttack);
void callPrintPokemon(POKEMON **pokes, int indexPokemon);
void callPrintAttack(POKEMON **pokes, int indexPokemon, int indexAttack);

int main()
{
    
    int command = 0;
    int count = 0;
    int indexPokemon = 0;
    int indexAttack = 0;
    POKEMON **pokes = NULL;
    
    scanf("%d", &command);

    while(command != 0){

        switch(command)
        {
            case 1:
                count++;
                pokes = callAddPokemon(pokes, count);
            break;
            case 2:
                scanf("%d", &indexPokemon);
                scanf("%d", &indexAttack);

                callAddAttack(pokes, indexPokemon, indexAttack);
            break;
            case 3:
                scanf("%d", &indexPokemon);
                callPrintPokemon(pokes, indexPokemon);
            break;
            case 4:
                scanf("%d", &indexPokemon);
                scanf("%d", &indexAttack);
                callPrintAttack(pokes, indexPokemon, indexAttack);
            break;
        }
        scanf("%d", &command);
    }
    
    removePokemon(pokes, count);
    
    return 0;
}

POKEMON** callAddPokemon(POKEMON **pokes, int count)
{
    char name[51], primaryType[21], secundaryType[21];
    int hp = 0, attack = 0, defense = 0, spAttack = 0, spDefense = 0, speed = 0;

    scanf("%s", name);
    scanf("%s", primaryType);
    scanf("%s", secundaryType);
    scanf("%d", &hp);
    scanf("%d", &attack);
    scanf("%d", &defense);
    scanf("%d", &spAttack);
    scanf("%d", &spDefense);
    scanf("%d", &speed);
    
    pokes = (POKEMON**) realloc(pokes, count*sizeof(POKEMON**));
    
    pokes[count-1] = addPokemon(name, primaryType, secundaryType, 
            hp, attack, defense, spAttack, spDefense, speed);
    
    return pokes;
}

void callAddAttack(POKEMON **pokes, int indexPokemon, int indexAttack)
{
    char nameAttack[21], attackClass;
    int basePower = 0;
    float accuracy = 0;

    scanf("%s", nameAttack);
    scanf("%d", &basePower);
    scanf("%f", &accuracy);
    scanf(" %c", &attackClass);

    addAttack(pokes[indexPokemon], indexAttack, nameAttack, basePower, accuracy, attackClass);
}

void callPrintPokemon(POKEMON **pokes, int indexPokemon)
{
    printPokemon(pokes[indexPokemon]);
}

void callPrintAttack(POKEMON **pokes, int indexPokemon, int indexAttack)
{
    printAttack(pokes[indexPokemon], indexAttack);
}


