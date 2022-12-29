#include "logisticmesh.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

static float get_cities_distance(int x1, int y1, int x2, int y2);
static VERTEX* input_to_vertex(char* input);

struct logisticmesh_t
{
    GRAPH* graph;
};

LOGISTIC_MESH* logistic_mesh_create(int number_of_cities)
{
    LOGISTIC_MESH* logistic_mesh = (LOGISTIC_MESH*) malloc(sizeof(LOGISTIC_MESH));
    logistic_mesh->graph = graph_create(number_of_cities); 
    
    return logistic_mesh;
}

void print_central_city(LOGISTIC_MESH* logistic_mesh)
{
    float* array = get_greater_distances(logistic_mesh->graph);
    
    print_vertex(get_central_vertex(logistic_mesh->graph, array));
    
    free(array);
}

void print_peripheral_city(LOGISTIC_MESH* logistic_mesh)
{
    float* array = get_greater_distances(logistic_mesh->graph);

    print_vertex(get_peripheral_vertex(logistic_mesh->graph, array));
    
    free(array);
}

void print_furthest_city_from_peripheral(LOGISTIC_MESH* logistic_mesh)
{
    float* array = get_greater_distances(logistic_mesh->graph);

    print_vertex(get_furthest_from_peripheral(logistic_mesh->graph, array));
    
    free(array);
}

void logistic_mesh_delete(LOGISTIC_MESH* logistic_mesh)
{
    graph_delete(logistic_mesh->graph);
    free(logistic_mesh);
}

void insert_highway_between_cities(LOGISTIC_MESH* logistic_mesh, char* source_city, char* city_destination)
{
    VERTEX* source = input_to_vertex(source_city);
    VERTEX* destination = input_to_vertex(city_destination);

    float distance = get_cities_distance(
        get_x_vertex(source), get_y_vertex(source),
        get_x_vertex(destination), get_y_vertex(destination));

    graph_insert_edge(logistic_mesh->graph, source, destination, distance); 


    free(source);
    free(destination);
}

void add_city(LOGISTIC_MESH* logistic_mesh, char* input)
{
    graph_add_vertex(logistic_mesh->graph, input_to_vertex(input));
}

float get_cities_distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void apply_floyd_warshall(LOGISTIC_MESH* logistic_mesh)
{
    floyd_warshall(logistic_mesh->graph);
}

VERTEX* input_to_vertex(char* input)
{
    char* coordinate = NULL;
    int x, y;

    coordinate = strtok(input, ",");
    x = atoi(coordinate);

    coordinate = strtok(NULL, ",");
    y = atoi(coordinate);

    return vertex_create(x, y);
}
