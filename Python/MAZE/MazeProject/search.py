"""
Python Data Structures - A Game-Based Approach
Robin Andrews - https://compucademy.net/
Search Algorithms for use in GUI.
"""
import config
import heapq
import helper_functions as helpers
from collections import deque


class PriorityQueue:
    def __init__(self):
        self.elements = []

    def is_empty(self):
        return len(self.elements) == 0

    def put(self, item, priority):
        heapq.heappush(self.elements, (priority, item))

    def get(self):
        return heapq.heappop(self.elements)[1]


def dfs(board, start, goal):
    stack = [start]
    visited = set()
    full_path = []

    while stack:
        current = stack.pop()
        full_path.append(current)
        if current == goal:
            return full_path
        for direction in ["up", "right", "down", "left"]:  # Other orders are fine too.
            row_offset, col_offset = config.offsets[direction]
            neighbour = (current[0] + row_offset, current[1] + col_offset)
            if helpers.is_legal_pos(board, neighbour) and neighbour not in visited:
                stack.append(neighbour)
                visited.add(neighbour)


def bfs(board, start, goal):
    queue = deque()
    queue.append(start)
    visited = set()
    full_path = []

    while queue:
        current = queue.popleft()
        full_path.append(current)
        if current == goal:
            return full_path
        for direction in ["up", "right", "down", "left"]:
            row_offset, col_offset = config.offsets[direction]
            neighbour = (current[0] + row_offset, current[1] + col_offset)
            if helpers.is_legal_pos(board, neighbour) and neighbour not in visited:
                queue.append(neighbour)
                visited.add(neighbour)


def heuristic(a, b):
    x1, y1 = a
    x2, y2 = b
    return abs(x1 - x2) + abs(y1 - y2)


def a_star(board, start_pos, goal_pos):
    pq = PriorityQueue()
    pq.put(start_pos, 0)
    g_values = {}
    g_values[start_pos] = 0
    full_path = []

    while not pq.is_empty():
        current_cell_pos = pq.get()
        full_path.append(current_cell_pos)
        if current_cell_pos == goal_pos:
            return full_path
        for direction in ["up", "right", "down", "left"]:
            row_offset, col_offset = config.offsets[direction]
            neighbour = (current_cell_pos[0] + row_offset, current_cell_pos[1] + col_offset)
            new_cost = g_values[current_cell_pos] + 1  # Would be edge weight in a weighted graph
            if helpers.is_legal_pos(board, neighbour):
                # Second check only applies to weighted graph.
                if neighbour not in g_values or new_cost < g_values[neighbour]:
                    g_values[neighbour] = new_cost
                    f_value = new_cost + heuristic(goal_pos, neighbour)
                    pq.put(neighbour, f_value)
