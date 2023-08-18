import sys
from heapq import heapify, heappush, heappop


def dijsktra(graph, src, dest):
    inf = sys.maxsize

    node_data = {
        "A": {"cost": inf, "pred": []},
        "B": {"cost": inf, "pred": []},
        "C": {"cost": inf, "pred": []},
        "D": {"cost": inf, "pred": []},
        "E": {"cost": inf, "pred": []},
    }

    node_data[src]["cost"] = 0
    visited = []
    temp = src
    for i in range(4):
        if temp not in visited:
            visited.append(temp)
            min_heap = []
            for j in graph[temp]:
                if j not in visited:
                    cost = node_data[temp]["cost"] + graph[temp][j]
                    if cost < node_data[j]["cost"]:
                        node_data[j]["cost"] = cost
                        node_data[j]["pred"] = node_data[temp]["pred"] + list(temp)
                    heappush(min_heap, (node_data[j]["cost"], j))
        heapify(min_heap)
        temp = min_heap[0][1]
    print("Shortest Distance: " + str(node_data[dest]["cost"]))
    print("Shortest Path: " + str(node_data[dest]["pred"] + list(dest)))


if __name__ == "__main__":

    graph = {
        "A": {"B": 6, "D": 1},
        "B": {"A": 6, "C": 5, "D": 2, "E": 2},
        "C": {"B": 5, "E": 5},
        "D": {"A": 1, "B": 2, "E": 1},
        "E": {"B": 2, "C": 5, "D": 1},
    }

    source = "A"
    destination = "C"

    dijsktra(graph, source, destination)
