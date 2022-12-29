#ifndef GAME_H
#define GAME_H

typedef struct game_t GAME;

#include "util.h"

GAME* game_create(char *name, char *company, int releaseYear);
void game_delete(GAME* game);

char* game_get_name(GAME* game);
int game_get_release_year(GAME* game);

boolean game_is_greater(GAME* game_a, GAME* game_b);
boolean game_is_smaller(GAME* game_a, GAME* game_b);

#endif // GAME_H