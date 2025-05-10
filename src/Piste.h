#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm> // Inclure la bibliothèque pour utiliser la fonction "shuffle"
using namespace std;

enum class Direction {
    HORIZONTAL,
    VERTICAL
};

class Wall {
public:
    int x;
    int y;
    Direction direction;
    Wall(int x_, int y_, Direction dir_);
    };

//La classe cellule
class Cell {
public:
    bool visited = false;
    bool top_wall = true;
    bool right_wall = true;
    bool bottom_wall = true;
    bool left_wall = true;
};

//La classe labyrinthe
class Maze {
public:
    int width;
    int height;
    vector<Cell> cells;
    vector<Wall> walls;
    Maze(int w, int h);

void generate() {
        mt19937 rng;
        rng.seed(time(nullptr));
        shuffle(walls.begin(), walls.end(), rng);

        for (const auto& wall : walls) {
            int x = wall.x;
            int y = wall.y;

            if (wall.direction == Direction::HORIZONTAL) {
                if (y == 0 || cells[x + y * width].visited || cells[x + (y - 1) * width].visited) {
                    continue;
                }
                cells[x + y * width].top_wall = false;
                cells[x + (y - 1) * width].bottom_wall = false;
            }
            else {
                if (x == 0 || cells[x + y * width].visited || cells[(x - 1) + y * width].visited) {
                    continue;
                }
                cells[x + y * width].left_wall = false;
                cells[(x - 1) + y * width].right_wall = false;
            }

            cells[x + y * width].visited = true;
        }
    }


std::string generate_maze(int width, int height) {
    Maze maze(width, height);
    maze.generate();

    std::string output = "";

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0 && y == 0) {
                output += "+-";
            } else if (x == 0 && y == height - 1) {
                output += "+-";
            } else if (y == height - 1 && x > 0 && x < width - 1) {
                output += "-+";
            } else if (y == height - 1 && x == width - 1) {
                output += "-+";
            } else if (y == 0) {
                output += "-+";
            } else if (x == 0) {
                output += "| ";
            } else if (x == width - 1) {
                output += " |";
            } else if (y >= 5 && y < 18 && x == 6) {
                output += "| ";
            } else if (y == 18 && x == 6) {
                output += "| ";
            } else if (y == 19 && x >= 6 && x < 18) {
                output += "+-";
            } else if (y > 12 && y < 25 && x == width - 6) {
                output += " |";
            } else if (y == 12 && x >= 13 && x < width - 5) {
                output += "-+";
            } else {
                output += "  ";
            }
        }
        output += "\n";
    }

    return output;
}
};

