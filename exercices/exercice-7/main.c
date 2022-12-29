#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <string.h>
#include "logisticmesh.h"

int main()
{
    int n = 0;
    char* input = NULL;

    scanf("%d", &n);
    extra_line_end();

    LOGISTIC_MESH* logistic_mesh = logistic_mesh_create(n);

    for (int i = 0; i < n; i++)
    {
        input = read_line();

        add_city(logistic_mesh, input);

        free(input);
    }
    
    scanf("%d", &n);
    extra_line_end();

    for (int i = 0; i < n; i++)
    {
        char* source;
        char* destination;

        input = read_line();

        source = strtok(input, ":");
        destination = strtok(NULL, ":");

        insert_highway_between_cities(logistic_mesh, source, destination);   

        free(input);
    }
    
    apply_floyd_warshall(logistic_mesh);

    print_central_city(logistic_mesh);
    print_peripheral_city(logistic_mesh);
    print_furthest_city_from_peripheral(logistic_mesh);

    logistic_mesh_delete(logistic_mesh);

    return 0;
}

