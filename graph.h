#ifndef GRAPH_H
#define GRAPH_H

struct Graph{
    int vertices_amount;
    int** relations;
};

struct Graph* create_graph(int v);
void graph_delete(struct Graph* graph);
void graph_add_relation(struct Graph* graph, int vertex, int relation);

#endif // GRAPH_H
