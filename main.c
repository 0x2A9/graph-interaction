#include "graph.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int va = 7;
    struct Graph* graph = create_graph(va);

    printf("%d\n", graph->vertices_amount);

    int **r = graph->relations;

    graph_add_relation(graph, 5, 3);

    for (int i = 0; i < va; i++) {
        for (int j = 0; j < va; j++) {
            printf("%d ",  *( *(r + i) + j));
        }
        printf("\n");
    }

    graph_delete(graph);
}
