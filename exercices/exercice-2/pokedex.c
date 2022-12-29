#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pokedex.h"

struct atributes_h
{

    int hp;
    int attack;
    int defense;
    int spAttack;
    int spDefense;
    int speed;

};

struct attacks_h
{

    char name[21];
    int basePower;
    float accuracy;
    char attackClass; // p = physical; s = special

};

struct pokemon_
{

    char name[51];
    char primaryType[21];
    char secundaryType[21];
    ATRIBUTES atributes;
    ATTACK attacks[4];

};

POKEMON* addPokemon(char *name, char *primaryType, char *secundaryType, 
        int hp, int attack, int defense, int spAttack, int spDefense, int speed)
{

    ATRIBUTES atributes;
    atributes.hp = hp;
    atributes.attack = attack;
    atributes.defense = defense;
    atributes.spAttack = spAttack;
    atributes.spDefense = spDefense;
    atributes.speed = speed;
    
    POKEMON *pokemon = (POKEMON*) malloc(sizeof(POKEMON));
    
    strcpy(pokemon->name, name);
    strcpy(pokemon->primaryType, primaryType);
    strcpy(pokemon->secundaryType, secundaryType);
    pokemon->atributes = atributes;
    
    return pokemon;

}

void addAttack(POKEMON *pokemon, int indexAttack, char *name, int basePower, int accuracy, char attackClass)
{
        
    strcpy(pokemon->attacks[indexAttack].name, name);
    pokemon->attacks[indexAttack].basePower =  basePower;
    pokemon->attacks[indexAttack].accuracy =  accuracy;
    pokemon->attacks[indexAttack].attackClass =  attackClass;

}

void printPokemon(POKEMON *pokemon)
{

    printf("Nome do Pokemon: %s\n", pokemon->name);
    printf("Tipo primario: %s\n", pokemon->primaryType);
    printf("Tipo secundario: %s\n", pokemon->secundaryType);
    printAtributes(pokemon->atributes);

}

void printAtributes(ATRIBUTES atributes)
{

    printf("Status:\n");
    printf("\tHP: %d\n", atributes.hp);
    printf("\tAtaque: %d\n", atributes.attack);
    printf("\tDefesa: %d\n", atributes.defense);
    printf("\tAtaque Especial: %d\n", atributes.spAttack);
    printf("\tDefesa Especial: %d\n", atributes.spDefense);
    printf("\tVelocidade: %d\n\n", atributes.speed);

}

void printAttack(POKEMON *pokemon, int indexAttack)
{
    printf("Nome do Ataque: %s\n", pokemon->attacks[indexAttack].name);
    printf("Poder base: %d\n", pokemon->attacks[indexAttack].basePower);
    printf("Acuracia: %f\n", pokemon->attacks[indexAttack].accuracy);
    printf("Classe: %c\n\n", pokemon->attacks[indexAttack].attackClass);
}


void removePokemon(POKEMON **pokemon, int count)
{
    for(int i=0; i<count; i++)
    {
        free(pokemon[i]);
    }
    free(pokemon);
}
