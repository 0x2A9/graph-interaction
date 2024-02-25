#ifndef GRAPH_H
#define GRAPH_H

struct Graph{
    int vertex_amount;
    int** relations;
};

struct Graph* create_graph(int v);
void graph_delete(struct Graph* graph);
void graph_add_relation(struct Graph* graph, int vertex, int relation);
void graph_display_relations(struct Graph* graph);

#endif // GRAPH_H
