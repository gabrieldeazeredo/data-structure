#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

static void graph_inicialize(GRAPH* graph);

struct graph_t
{
    float **graph_matrix;
    VERTEX **list_vertex;
    int num_vertex;
};

struct vertex_t
{
    int x;
    int y;
}; 

GRAPH* graph_create(int num_vertex)
{
    GRAPH* graph = (GRAPH*) malloc(sizeof(GRAPH));
    
    graph->num_vertex = num_vertex;

    graph->list_vertex = (VERTEX**) malloc(num_vertex*sizeof(VERTEX*));

    graph_inicialize(graph);
    

    return graph;
}

void graph_inicialize(GRAPH* graph)
{
    int num_vertex = graph->num_vertex;  
    graph->graph_matrix = (float**) malloc(num_vertex*sizeof(float*));
    
    for (int i = 0; i < num_vertex; i++)
    {
        graph->graph_matrix[i] = (float*) malloc(num_vertex*sizeof(float));
        graph->list_vertex[i] = NULL;
    }

    for (int i = 0; i < graph->num_vertex; i++)
    {
        for (int j = 0; j < graph->num_vertex; j++)
        {
            if (i == j)
            {
                graph->graph_matrix[i][j] = 0;
            }
            else
            {
                graph->graph_matrix[i][j] = INF;
            }  
        }   
    } 
    
}

void graph_add_vertex(GRAPH* graph, VERTEX* vertex)
{
    for (int i = 0; i < graph->num_vertex; i++)
    {
        if (graph->list_vertex[i] == NULL)
        {
            graph->list_vertex[i] = vertex;
            break;
        }
    }
}

VERTEX* vertex_create(int x, int y)
{
    VERTEX* newVertex = (VERTEX*) malloc(sizeof(VERTEX));
    
    newVertex->x = x;
    newVertex->y = y;

    return newVertex;
}

void graph_insert_edge(GRAPH* graph, VERTEX* source, VERTEX* destination, float weight)
{
    int index_source = get_index_vertex(graph, source); 
    int index_destination = get_index_vertex(graph, destination);
    
    graph->graph_matrix[index_destination][index_source] = weight;
}

void graph_delete(GRAPH* graph)
{
    for (int i = 0; i < graph->num_vertex; i++)
    {
        free(graph->list_vertex[i]);
        free(graph->graph_matrix[i]);
    }    
    free(graph->list_vertex);
    free(graph->graph_matrix);
    free(graph);
}

int get_index_vertex(GRAPH* graph, VERTEX* vertex)
{

    int vertex_x = vertex->x;
    int vertex_y = vertex->y;

    for (int i = 0; i < graph->num_vertex; i++)
    {
        int loop_vertex_x = graph->list_vertex[i]->x;
        int loop_vertex_y = graph->list_vertex[i]->y;

        if (vertex_x == loop_vertex_x && vertex_y == loop_vertex_y)
        {
            return i;
        }
    }

    return -1;
}

int get_x_vertex(VERTEX* vertex)
{
    return vertex->x;
}

int get_y_vertex(VERTEX* vertex)
{
    return vertex->y;
}

void floyd_warshall(GRAPH* graph)
{
    int n = graph->num_vertex;
    float** mat = graph->graph_matrix;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] > mat[i][k] + mat[k][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }
}

void print_vertex(VERTEX* vertex)
{
    printf("%d,%d\n", vertex->x, vertex->y);
}

VERTEX* get_central_vertex(GRAPH* graph, float* array_distances)
{
    int central_vertex_index = 0;

    for (int i = 0; i < graph->num_vertex; i++)
    {
        if (array_distances[i] < array_distances[central_vertex_index])
        {
            central_vertex_index = i;
        }
    }

    return graph->list_vertex[central_vertex_index];
}

VERTEX* get_peripheral_vertex(GRAPH* graph, float* array_distances)
{
    int peripheral_vertex_index = 0;

    for (int i = 0; i < graph->num_vertex; i++)
    {
        if (array_distances[i] > array_distances[peripheral_vertex_index])
        {
            peripheral_vertex_index = i;
        }
    }

    return graph->list_vertex[peripheral_vertex_index];
}

VERTEX* get_furthest_from_peripheral(GRAPH* graph, float* array_distances)
{
    int peripheral_vertex_index = get_index_vertex(graph, get_peripheral_vertex(graph, array_distances));
    int furthest_from_peripheral_index = 0;

    for (int i = 0; i < graph->num_vertex; i++)
    {
        if (graph->graph_matrix[i][peripheral_vertex_index] > 
            graph->graph_matrix[furthest_from_peripheral_index][peripheral_vertex_index])
        {
            furthest_from_peripheral_index = i;
        }
    }
    
    return graph->list_vertex[furthest_from_peripheral_index];
}

float* get_greater_distances(GRAPH* graph)
{
    float* array = (float*) malloc(sizeof(float)*graph->num_vertex);

    for (int i = 0; i < graph->num_vertex; i++)
    {
        array[i] = graph->graph_matrix[0][i];

        for (int j = 0; j < graph->num_vertex; j++)
        {
            if (graph->graph_matrix[j][i] > array[i])
            {
                array[i] = graph->graph_matrix[j][i];
            }
        }
    }

    return array;
}