#include <iostream>
#include "Piste.h"

using namespace std;


int main() {
    const int WIDTH = 28;
    const int HEIGHT = 28;
    Maze maze(WIDTH, HEIGHT);
    maze.generate();

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 && y == 0) {
                cout << "+-";
            }
            else if (x == 0 && y == HEIGHT-1) {
                cout << "+-";
            }
            else if (y == HEIGHT-1 && x > 0 && x < WIDTH-1) { 
                cout << "-+";
            }
            else if (y == HEIGHT-1 && x == WIDTH-1) { 
                cout << "-+";
            }
            else if (y == 0) {
                cout << "-+";
            }
            else if (x == 0) {
                cout << "| ";
            }
            else if (x == WIDTH-1) {
                cout << " |";
            }
            else if (y >= 5 && y < 18 &&  x == 6) {
                cout << "| ";
            }
            else if (y == 18 && x == 6) {
                cout << "| ";
            }
            else if (y == 19 && x >= 6 && x < 18) {
                cout << "+-";
            }
           
            // 2ème L
            
           else if (y > 0 && y < 10 &&  x == WIDTH-10) {
                cout << " |";
            }
            else if (y == 10 && x >= WIDTH-10 && x < 28) {
                cout << "+-";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}
