#include "graph.h"

struct graph_t
{
    tweight mat[MAX_VERTEX][MAX_VERTEX];
    int num_vertex;
};

/* struct vertex_t
{
    
}; */


void graph_create(GRAPH* graph, int num_vertex)
{
    graph->num_vertex = num_vertex;

    for (int i = 0; i < graph->num_vertex; i++)
    {
        for (int j = 0; j < graph->num_vertex; j++)
        {
            graph->mat[i][j] = 0;
        }   
    } 
}

void graph_insert_edge(GRAPH* graph, tvertex vertex_1, tvertex vertex_2, tweight weight)
{
    graph->mat[vertex_1][vertex_2] = weight;
}

int graph_search_edge(GRAPH* graph, tvertex vertex_1, tvertex vertex_2)
{
    return graph->mat[vertex_1][vertex_2] != 0;
}

void graph_remove_edge(GRAPH* graph, tvertex vertex_1, tvertex vertex_2)
{
    graph->mat[vertex_1][vertex_2] = 0;
}

int graph_search_adjacency(GRAPH* graph, tvertex vertex_1)
{
    tvertex temp_vertex;

    for (temp_vertex = 0; temp_vertex < graph->num_vertex; temp_vertex++)
    {
        if (graph->mat[vertex_1][temp_vertex] != 0)
        {
            return 1;
        }
    }
    return 0;
}

tpointer graph_get_pointer_first_adj(GRAPH* graph, tvertex vertex_1)
{
    tpointer temp_pointer;

    for (temp_pointer = 0; temp_pointer < graph->num_vertex; temp_pointer++)
    {
        if (graph->mat[vertex_1][temp_pointer] != 0)
        {
            return temp_pointer;
        }
    }
    return NULL;
}

tpointer graph_get_pointer_next_adj(GRAPH* graph, tvertex vertex_1, tpointer temp_pointer)
{

    for (temp_pointer++; temp_pointer < graph->num_vertex; temp_pointer++)
    {
        if (graph->mat[vertex_1][temp_pointer] != 0)
        {
            return temp_pointer;
        }
    }
    return NULL;
}
