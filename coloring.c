#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "utils.h"

#define MIN_COLOR_AMOUNT 0
#define STARTING_VERTEX_INDEX 0

static bool is_color_amount_valid(int amount)
{
    return MIN_COLOR_AMOUNT < amount;
}

static bool is_coloring_applicable(struct Graph* graph, int * coloring, int current_c, int current_v)
{
    for (int i = 0; i < graph->vertex_amount; i++)
		if (graph->relations[current_v][i] == 1 && current_c == coloring[i])
			return false;

	return true;
}

static bool graph_color(struct Graph* graph, int * coloring, int color_amount, int current_v)
{
    if (current_v == graph->vertex_amount)
        return true;

    for (int i = 1; i <= color_amount; i++) {
        if (is_coloring_applicable(graph, coloring, i, current_v)) {
			coloring[current_v] = i;

			if (graph_color(graph, coloring, color_amount, current_v + 1) == true)
				return true;
		}
    }

    return false;
}

int* process_coloring(struct Graph* graph, int color_amount) 
{
    if (!is_color_amount_valid(color_amount))
    {
        printf("The amount of the colors should be bigger than %d", MIN_COLOR_AMOUNT);
        exit(1);
    }

    int * coloring = create_array(graph->vertex_amount);

    if (graph_color(graph, coloring, color_amount, STARTING_VERTEX_INDEX) == false)
    {
        printf("Coloring the currennt graph is impossible");
        exit(1);
    }

    return coloring;
}

void display_coloring(int* coloring, int vertex_amount)
{
    for (int i = 0; i < vertex_amount; i++)
        printf("Vertex #%d colored with %d\n", i+1, coloring[i]);
}
