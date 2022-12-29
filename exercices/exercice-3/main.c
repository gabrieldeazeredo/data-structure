#include "catalog.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
    char *name = NULL;
    char *company = NULL;
    char *input = NULL;
    int releaseYear = 0, count = 0;

    CATALOG *catalog = catalogCreate();
    
    name = read_line();
    count++;

    while(strcmp(name, "F") != 0){

        company = read_line();
        scanf("%d", &releaseYear);
        extra_line_end();        

        sighUpGame(count, catalog, name, company, releaseYear);
        free(name);
        free(company);
        name = read_line();
        count++;
    }
    free(name);

    input = read_line();
        
    while(strcmp(input, "F") != 0){

        if(strcmp(input, "A") == 0)
        {
            scanf("%d", &releaseYear);
            extra_line_end();
            searchByYear(catalog, releaseYear);
        } 
        else
        {
            company = read_line();
            searchByCompany(catalog, company);
            free(company);
        }
        free(input);
        input = read_line();
    }
    
    free(input);
    deleteCatalog(catalog);

    return 0;
}
