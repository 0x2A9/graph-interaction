#include "utils.h"
#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

struct Graph* create_graph(int v) 
{
    if (v <= 0 || v > 100)
    {
        printf("The amount of the vertices should be between 1 and 100");
        exit(1);
    }

    struct Graph* graph = malloc(sizeof(struct Graph));

    graph->vertices_amount = v;
    graph->vertices = create_matrix(v);
    
    return graph;
}

void delete_graph(struct Graph* graph)
{
    // clear heap after using the `malloc` to prevent memory leaks
    delete_matrix((*graph).vertices, (*graph).vertices_amount);
    free(graph);
}