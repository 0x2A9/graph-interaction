#include "graph.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct Graph* graph = create_graph(7);
    printf("%d\n", (*graph).vertices_amount);

    delete_graph(graph);
}
