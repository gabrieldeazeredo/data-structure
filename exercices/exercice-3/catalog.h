#ifndef CATALOG_H
#define CATALOG_H



typedef struct game_ GAME;
typedef struct catalog_ CATALOG;
#define TAM 1000

CATALOG* catalogCreate();
void sighUpGame(int count, CATALOG *catalog, char *name, char *company, int releaseYear);
void addGame (int count, CATALOG *catalog, GAME *game);
void searchByYear(CATALOG *catalog, int year);
void searchByCompany(CATALOG *catalog, char *company);
void deleteCatalog(CATALOG* catalog);


#endif //CATALOG_H
