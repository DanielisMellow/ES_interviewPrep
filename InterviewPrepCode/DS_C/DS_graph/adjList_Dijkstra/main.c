#include "adj_list.h"
#include "list.h"
#include "min_heap.h"
#include <stdint.h>

void print_path(int current_vertex, int parents[]) {
  if (parents[current_vertex] == -1) {
    return;
  }

  print_path(parents[current_vertex], parents);

  printf("%d ", current_vertex);
}

void print_set(int parents[], int distance[], int starting_vertex,
               graph *graph) {
  if (!(graph) || !(parents)) {
    return;
  }

  printf("Vetex\tDistance\tPath\n");

  for (int i = 0; i < graph->vertex_amount; i++) {
    printf("%d -> %d\t%d\t\t%d ", starting_vertex, i, distance[i],
           starting_vertex);
    print_path(i, parents);
    printf("\n");
  }
}

node *find_the_node(graph *graph, unsigned int src, unsigned int dest) {
  if (!(graph)) {
    printf("Graph empty\n");
    return NULL;
  }
  node *found;
  found = search_for_node(graph->adj_list[src], dest);
  return found;
}

void dijkstra_alg(graph *graph, int starting_vertex) {
  min_heap *min_heap = create_new_heap(graph->vertex_amount);
  int *previous = (int *)calloc(graph->vertex_amount, sizeof(int));
  int *distance = (int *)calloc(graph->vertex_amount, sizeof(int));

  if (!(previous) || !(distance)) {
    return;
  }

  for (int u = 0; u < graph->vertex_amount; u++) {
    distance[u] = INT32_MAX;
    previous[u] = -1;
    insert_into_heap(min_heap, u, distance[u]);
  }

  decrease_key(min_heap, starting_vertex, 0);
  distance[starting_vertex] = 0;

  while (!(is_heap_empty(min_heap))) {
    int u = extract_min(min_heap);
    for (int v = 0; v < graph->vertex_amount; v++) {
      node *u_v = find_the_node(graph, u, v);
      if (!(u_v)) {
        continue;
      }
      int tmp_distance = distance[u] + u_v->weight;

      if (u_v->weight && is_in_heap(min_heap, v) && distance[u] != INT32_MAX &&
          tmp_distance < distance[v]) {
        distance[v] = tmp_distance;
        previous[v] = u;
        decrease_key(min_heap, v, u_v->weight);
      }
    }
  }
  print_set(previous, distance, starting_vertex, graph);

  free(previous);
  free(distance);
  free_heap(min_heap);
}

int main(void) {
  /* Let us create the following graph
           2    3
       (0)--(1)--(2)
       |    / \   |
      6|  8/   \5 |7
       |  /     \ |
       (3)-------(4)
            9
  */

  int vertex_amount = 5;
  graph *my_graph = create_graph(vertex_amount);

  add_edge(my_graph, 0, 1, 2);
  add_edge(my_graph, 0, 3, 6);
  add_edge(my_graph, 1, 2, 3);
  add_edge(my_graph, 1, 3, 8);
  add_edge(my_graph, 1, 4, 5);
  add_edge(my_graph, 2, 4, 7);
  add_edge(my_graph, 3, 4, 9);

  print_graph(my_graph);
  printf("\n\n");
  dijkstra_alg(my_graph, 0);

  free_graph(my_graph);

  return 0;
}
