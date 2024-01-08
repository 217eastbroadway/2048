#include "gameLogic.h"

namespace gameLogic{
    bool generateNewCell(int v[4][4], int width, int height, int luckyRate){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(v[i][j] == 0){ //Matrix isn't full. (Can generate more cells)
                    srand(time(NULL));
                    int x, y;
                    do{
                        x = rand()%4;
                        y = rand()%4;
                    }while(v[x][y] != 0);
                    
                    rand()%100 < luckyRate ? v[x][y] = 4 : v[x][y] = 2;
                    return true; //Matrix has a new cell.
                }
                
        return false; //Matrix is full. (game lost)
    }
}