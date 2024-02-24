#ifndef GRAPH_H
#define GRAPH_H

struct Graph{
    int vertices_amount;
    int** vertices;
};

struct Graph* create_graph(int v);
void delete_graph(struct Graph* graph);

#endif // GRAPH_H
