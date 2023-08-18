"""
Python Data Structures - A Game-Based Approach
Robin Andrews - https://compucademy.net/
"""

import config
import turtle
import search
import helper_functions as helpers
import tkinter as tk


class MazeGUI:
    def __init__(self, maze_grid, maze_dimensions, maze_obstacles, opponent_start_pos):
        self.maze_grid = maze_grid
        self.maze_dimensions = maze_dimensions  # rows, columns.
        self.maze_obstacles = maze_obstacles
        self.opponent_start_pos = self.opponent_pos = opponent_start_pos
        self.opponent_path = None
        self.doing_path = False
        self.show_path = True
        self.treasure_pos = (0, 0)
        self.treasure_set = False
        self.path_started = False
        self.algorithm = "dfs"

        # Turtle Window
        self.screen = turtle.Screen()
        # self.screen.setup(config.WIDTH, config.HEIGHT)
        self.screen.setup(width=1.0, height=1.0)  # For full screen.
        self.screen.title("Path Finding with Python Turtle Graphics")
        self.canvas = self.screen.getcanvas()

        # Prepare game and start game loop.
        self.init_screen()
        self.reset()

    def init_screen(self):
        # Create screen and controls
        self.screen.bgcolor("black")
        self.screen.tracer(0)  # Disable animation - we will update screen manually.
        self.create_controls()
        self.screen.listen()

        # Builder
        self.builder = turtle.Turtle()
        self.builder.shape("square")
        self.builder.color("red")
        self.builder.shapesize(18 / 20)  # 20px is default square size.
        self.builder.hideturtle()
        self.builder.penup()

        # Opponent
        self.opponent = turtle.Turtle()
        self.opponent.shape("square")
        self.opponent.color("purple")
        self.opponent.shapesize(18 / 20)  # 20px is default square size.
        self.opponent.penup()

        # Treasure
        self.treasure = turtle.Turtle()
        self.treasure.shape("circle")
        self.treasure.color("yellow")
        self.treasure.shapesize(18 / 20)  # 20px is default square size.
        self.treasure.penup()

        # Score turtle
        self.score_turtle = turtle.Turtle()
        self.score_turtle.hideturtle()
        self.score_turtle.color("white")
        self.score_turtle.penup()
        self.score_turtle.goto(0, -350)

        # Draw game objects and maze walls
        self.draw_maze(self.maze_obstacles)  # Draw maze walls

    def reset(self):
        # Stop any existing movement and clear trail
        self.opponent.clearstamps()
        self.opponent_path = None
        self.stop_doing_path()

        # Position/show game objects
        self.opponent_pos = self.opponent_start_pos
        self.treasure.hideturtle()
        self.treasure_set = False
        self.draw_piece(self.opponent, self.opponent_start_pos)

        # Start game
        self.path_started = False
        self.bind_events()  # Some events may have been unbound to prevent event stacking.
        self.screen.update()
        self.animation_loop()

    def set_treasure_pos_from_click(self, x, y):
        # Don't allow this once path has started:
        if not self.path_started:
            self.treasure_pos = helpers.grid_pos_from_screen_coords((x, y), self.maze_dimensions)
            if self.treasure_pos not in self.maze_obstacles:
                self.treasure.goto(helpers.screen_coords_from_grid_pos(self.treasure_pos, self.maze_dimensions))
                self.treasure.showturtle()
                self.treasure_set = True
                self.screen.update()

    def bind_events(self):
        self.screen.onkey(self.do_algorithm, "s")
        self.screen.onkey(self.toggle_doing_path, "space")
        self.screen.onclick(self.set_treasure_pos_from_click)

    def create_controls(self):
        self.reset_button = tk.Button(
            self.canvas.master,
            width=5,
            text="Reset",
            background="green",
            foreground="white",
            bd=0,
            activebackground="green",
            activeforeground="white",
            font=config.BUTTON_FONT,
            command=lambda: self.reset(),
        )
        self.path_button = tk.Button(
            self.canvas.master,
            width=5,
            text="Path",
            background="green",
            foreground="red",
            bd=0,
            activebackground="green",
            activeforeground="white",
            font=config.BUTTON_FONT,
            command=self.toggle_show_path,
        )

        self.dfs_button = tk.Button(
            self.canvas.master,
            width=5,
            text="DFS",
            background="green",
            foreground="red",
            bd=0,
            activebackground="green",
            activeforeground="white",
            font=config.BUTTON_FONT,
            command=lambda: self.update_algorithm("dfs"),
        )

        self.bfs_button = tk.Button(
            self.canvas.master,
            width=5,
            text="BFS",
            background="green",
            foreground="white",
            bd=0,
            activebackground="green",
            activeforeground="white",
            font=config.BUTTON_FONT,
            command=lambda: self.update_algorithm("bfs"),
        )

        self.a_star_button = tk.Button(
            self.canvas.master,
            width=5,
            text="A*",
            background="green",
            foreground="white",
            bd=0,
            activebackground="green",
            activeforeground="white",
            font=config.BUTTON_FONT,
            command=lambda: self.update_algorithm("a_star"),
        )

        self.canvas.create_window(-120, -340, window=self.reset_button)
        self.canvas.create_window(-60, -340, window=self.path_button)
        self.canvas.create_window(0, -340, window=self.dfs_button)
        self.canvas.create_window(60, -340, window=self.bfs_button)
        self.canvas.create_window(120, -340, window=self.a_star_button)

    def toggle_show_path(self):
        self.show_path = not self.show_path
        if self.show_path:
            self.path_button.config(fg="red")
        else:
            self.path_button.config(fg="white")

    def update_algorithm(self, alg):
        self.algorithm = alg
        buttons = [self.dfs_button, self.bfs_button, self.a_star_button]
        for button in buttons:
            button.config(fg="white")
        if alg == "dfs":
            self.dfs_button.config(fg="red")
        elif alg == "bfs":
            self.bfs_button.config(fg="red")
        elif alg == "a_star":
            self.a_star_button.config(fg="red")
        self.reset()

    def draw_maze(self, obstacles):
        for obstacle in obstacles:
            self.builder.goto(helpers.screen_coords_from_grid_pos(obstacle, self.maze_dimensions))
            self.builder.stamp()

    def draw_piece(self, piece, pos, stamp=False):
        piece.goto(helpers.screen_coords_from_grid_pos(pos, self.maze_dimensions))
        if stamp:
            piece.stamp()

    def toggle_doing_path(self):
        if self.path_started:
            if self.doing_path:
                self.stop_doing_path()
            else:
                self.start_or_continue_path()

    def do_algorithm(self):
        if self.treasure_set:  # Can't find path to null position.
            if self.algorithm == "dfs":
                self.opponent_path = search.dfs(self.maze_grid, self.opponent_start_pos,
                                                self.treasure_pos)
            elif self.algorithm == "bfs":
                self.opponent_path = search.bfs(self.maze_grid, self.opponent_start_pos,
                                                self.treasure_pos)
            elif self.algorithm == "a_star":
                self.opponent_path = search.a_star(self.maze_grid, self.opponent_start_pos,
                                                   self.treasure_pos)
            # Path is found
            if self.opponent_path is not None:
                self.path_started = True
                # Already started so disable key.
                # You might be surprised how important this is!
                self.screen.onkey(None, "s")
                self.start_or_continue_path()
            else:
                self.reset()  # Goal unreachable.

    def start_or_continue_path(self):
        self.doing_path = True
        self.animation_loop()

    def stop_doing_path(self):
        self.doing_path = False

    def animation_loop(self):
        if self.doing_path:
            # Get next position in path
            try:
                next_pos = self.opponent_path.pop(0)
            except IndexError:
                return
            # Move opponent to next position
            self.draw_piece(self.opponent, next_pos, self.show_path)
            # Check for collision with treasure
            if next_pos == self.treasure_pos:
                # Add extra functionality if required. E.g sounds.
                pass
            self.screen.update()
            turtle.ontimer(self.animation_loop, config.GAME_SPEED)


if __name__ == "__main__":
    maze_grid, maze_dimensions, maze_obstacles, player_start_pos, opponent_start_pos = helpers.read_maze_from_file(
        config.MAZE_FILE)
    MazeGUI(maze_grid, maze_dimensions, maze_obstacles, opponent_start_pos)
    turtle.done()
