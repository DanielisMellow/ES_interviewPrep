"""
Python Data Structures - A Game-Based Approach
Robin Andrews - https://compucademy.net/
Helper functions for use in GUI.
"""
import config


def screen_coords_from_grid_pos(pos, grid_dimensions):
    """
    Converts grid-based coordinates to screen based coordinates.
    """
    i, j = pos
    # 20 here is a turtle size of 18 plus 1 px border each side, so the size of one "cell".
    screen_x = - ((grid_dimensions[1] - 1) / 2 * 20) + (j * 20)
    screen_y = ((grid_dimensions[0] - 1) / 2 * 20) - (i * 20)
    return (screen_x, screen_y)


def grid_pos_from_screen_coords(pos, dimensions):
    """
    Converts screen-based coordinates to grid-based coordinates.
    """
    x, y = pos
    m, n = dimensions
    j = int((20 * (n / 2) + x) / 20)
    i = int((20 * (m / 2) - y) / 20)
    return (i, j)


def read_maze_from_file(file_name):
    """
    Reads a maze stored in a text file and returns a 2d list containing the maze representation.
    """
    try:
        with open(file_name) as fh:
            # Convert string maze to 2d list
            maze = [[char for char in line.strip("\n")] for line in fh]

            # Get maze dimensions
            num_cols_top_row = len(maze[0])
            num_rows = len(maze)

            # Check maze is rectangular
            for row in maze:
                if len(row) != num_cols_top_row:
                    print("The maze is not rectangular.")
                    raise SystemExit
            # Find obstacles and initial positions for player and opponent
            maze_obstacles = []
            for i in range(num_rows):
                for j in range(num_cols_top_row):
                    if maze[i][j] == config.OBSTACLE:
                        maze_obstacles.append((i, j))
                    elif maze[i][j] == config.PLAYER:
                        player_start_pos = (i, j)
                    elif maze[i][j] == config.OPPONENT:
                        opponent_start_pos = (i, j)

            return maze, (num_rows, num_cols_top_row), maze_obstacles, player_start_pos, opponent_start_pos
    except UnboundLocalError:
        print("The maze needs a player and an opponent.")
        raise SystemExit
    except OSError:
        print("There is a problem with the file you have selected.")
        raise SystemExit


def is_legal_pos(board, pos):
    """
    Determines whether a supplied position is legal in the context of a supplied board.
    """
    i, j = pos
    rows = len(board)
    cols = len(board[0])
    return 0 <= i < rows and 0 <= j < cols and board[i][j] != config.OBSTACLE
