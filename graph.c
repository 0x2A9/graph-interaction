#include "utils.h"
#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_VERTEX_AMOUNT 0
#define MAX_VERTEX_AMOUNT 100

static bool is_relation_valid(int vertex, int vertex_amount)
{
    return vertex > MIN_VERTEX_AMOUNT && vertex <= vertex_amount;
}

struct Graph* create_graph(int v) 
{
    if (v <= MIN_VERTEX_AMOUNT || v > MAX_VERTEX_AMOUNT)
    {
        printf("The amount of the vertices should be between %d and %d", MIN_VERTEX_AMOUNT, MAX_VERTEX_AMOUNT);
        exit(1);
    }

    struct Graph* graph = malloc(sizeof(struct Graph));

    graph->vertices_amount = v;
    graph->relations = create_matrix(v);
    
    return graph;
}

void graph_add_relation(struct Graph* graph, int vertex, int relation)
{
    int a = graph->vertices_amount;
    int** vertices = graph->relations;

    if (is_relation_valid(vertex, a) && is_relation_valid(relation, a))
    {
        vertices[vertex - 1][relation - 1] = 1;
	    vertices[relation - 1][vertex - 1] = 1;

        return;
    }

    printf("The relation index should be between %d and %d", MIN_VERTEX_AMOUNT, a);
    exit(1);
}

void graph_delete(struct Graph* graph)
{
    // clear heap after using the `malloc` to prevent memory leaks
    delete_matrix(graph->relations, graph->vertices_amount);
    free(graph);
}