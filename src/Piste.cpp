#include"Piste.h"
#include <string>

Wall::Wall(int x_, int y_, Direction dir_) : x(x_), y(y_), direction(dir_) {}

Maze::Maze(int w, int h) : width(w), height(h) {
    cells.resize(w * h);
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            if (x > 0) walls.push_back(Wall(x, y, Direction::VERTICAL));
               if (y > 0) walls.push_back(Wall(x, y, Direction::HORIZONTAL));
        }
    }
}



