#include <Prism.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

enum Direction{
    Up,
    Down,
    Left,
    Right
};

namespace gameLogic{
    bool updateGameMatrix(int v[4][4], int width, int height, Direction direct);

    bool generateNewCell(int v[4][4], int width, int height, int luckyRate); //Returns false if no cell can be created.

    bool isGameLost(int v[4][4]);
}