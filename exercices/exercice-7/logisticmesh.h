#ifndef LOGISTICMESH_H
#define LOGISTICMESH_H

#include "graph.h"

typedef struct logisticmesh_t LOGISTIC_MESH;

LOGISTIC_MESH* logistic_mesh_create(int number_of_cities);
void logistic_mesh_delete(LOGISTIC_MESH* logistic_mesh);
void insert_highway_between_cities(LOGISTIC_MESH* logistic_mesh, char* source_city, char* city_destination);
void add_city(LOGISTIC_MESH* logistic_mesh, char* input);


void apply_floyd_warshall(LOGISTIC_MESH* logistic_mesh);
void print_central_city(LOGISTIC_MESH* logistic_mesh);
void print_peripheral_city(LOGISTIC_MESH* logistic_mesh);
void print_furthest_city_from_peripheral(LOGISTIC_MESH* logistic_mesh);

#endif // LOGISTICMESH_H
