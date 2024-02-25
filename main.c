#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "utils.h"
#include "coloring.h"

int main(void)
{
    struct Graph* graph = create_graph(7);

    graph_add_relation(graph, 5, 3);
    graph_add_relation(graph, 4, 4);
    graph_add_relation(graph, 1, 3);

    int* coloring = process_coloring(graph, 4);

    graph_display_relations(graph);
    display_coloring(coloring, graph->vertex_amount);

    graph_delete(graph);
}
