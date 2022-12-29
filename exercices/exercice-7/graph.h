#ifndef GRAPH_H
#define GRAPH_H

#define INF 99999

typedef struct graph_t GRAPH;
typedef struct vertex_t VERTEX;

GRAPH* graph_create(int num_vertex); 
void graph_add_vertex(GRAPH* graph, VERTEX* vertex); // OK
void graph_insert_edge(GRAPH* graph, VERTEX* source, VERTEX* destination, float weight); // OK
void graph_delete(GRAPH* graph);

void floyd_warshall(GRAPH* graph);
void more_central(GRAPH* graph);
float* get_greater_distances(GRAPH* graph);
VERTEX* get_central_vertex(GRAPH* graph, float* array_distances);
VERTEX* get_furthest_from_peripheral(GRAPH* graph, float* array_distances);
VERTEX* get_peripheral_vertex(GRAPH* graph, float* array_distances);

VERTEX* vertex_create(int x, int y);
void print_vertex(VERTEX* vertex);
int get_index_vertex(GRAPH* graph, VERTEX* vertex);
int get_x_vertex(VERTEX* vertex);
int get_y_vertex(VERTEX* vertex);

#endif //GRAPH_H