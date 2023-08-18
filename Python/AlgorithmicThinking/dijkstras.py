import sys
INF = sys.maxsize


def dijkstra(graph, src):
    unvisited_min_distances = {vertex: INF for vertex in graph}
    visited_vertices = {}
    current_vertex = src  # The start node.
    unvisited_min_distances[current_vertex] = 0

    # While vertices remain unvisited
    while len(unvisited_min_distances) > 0:
        # Visit unvisited vertex with smallest known distance from start vertex.
        # Very inefficient - use priority queue in "real" version.
        current_vertex, current_distance = sorted(unvisited_min_distances.items(), key=lambda x: x[1])[0]
        
        # For each unvisited neighbor of the current vertex
        for neighbor, neighbor_distance in graph[current_vertex].items():
            # If a neighbor has been processed, skip it.
            if neighbor in visited_vertices:
                continue
            # Calculate the new distance if this route is taken.
            potential_new_distance = current_distance + neighbor_distance
            # If the calculated distance of this vertex is less than the known distance
            if potential_new_distance < unvisited_min_distances[neighbor]:
                # Update the distance for this neighbor.
                unvisited_min_distances[neighbor] = potential_new_distance
        # Add the current vertex to the visited vertices.
        visited_vertices[current_vertex] = current_distance
        # Remove the current vertex from the unvisited list (dictionary).
        del unvisited_min_distances[current_vertex]

    # Display results.
    print(sorted(visited_vertices.items()))


def main():
    graph = {
        "A": {"B": 6, "D": 1},
        "B": {"A": 6, "C": 5, "D": 2, "E": 2},
        "C": {"B": 5, "E": 5},
        "D": {"A": 1, "B": 2, "E": 1},
        "E": {"B": 2, "C": 5, "D": 1},
    }

    source = "A"
    dijkstra(graph, source)


if __name__ == "__main__":
    main()
