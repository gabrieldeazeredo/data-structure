#ifndef POKEDEX_H
#define POKEDEX_H

typedef struct attacks_h ATTACK;
typedef struct atributes_h ATRIBUTES;
typedef struct pokemon_ POKEMON; 

POKEMON* addPokemon(char *name, char *primaryType,char *secundaryType,
        int hp, int attack, int defense, int spAttack, int spDefense, int speed);

void addAttack(POKEMON *pokemon, int indexAttack, char *name, int basePower, int accuracy, char attackClass);
void printPokemon(POKEMON *pokemon);
void printAtributes(ATRIBUTES atributes);
void printAttack(POKEMON *pokemon, int indexAttack);
void removePokemon(POKEMON **pokemon, int count);

#endif //POKEDEX_H;
