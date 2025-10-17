#include "gameLogic.h"

namespace gameLogic{
    bool updateGameMatrix(int v[4][4], int width, int height, Direction direct){
        bool hasMoved = false;

        switch(direct){
            case Up:
                for(int i = 0; i < 4; i++)
                        for(int j = 0; j < 4; j++)
                            for(int x = j+1; x < 4; x++){
                            if(v[x][i] != 0 && v[j][i] != v[x][i])
                                break;
                            else if(v[j][i] == v[x][i]){
                                v[x][i] *= 2;
                                v[j][i] = 0;

                                j = x;
                                break;
                            }
                        }

               for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        if(v[j][i] == 0)
                            for(int x = j+1; x < 4; x++)
                                if(v[x][i] != 0){
                                    v[j][i] = v[x][i];
                                    v[x][i] = 0;
                                    hasMoved = true;
                                    break;
                                }
            break;

            case Down:
                for(int i = 0; i < 4; i++)
                    for(int j = 3; j >= 0; j--)
                        for(int x = j-1; x >= 0; x--){
                            if(v[x][i] != 0 && v[j][i] != v[x][i])
                                break;
                            else if(v[j][i] == v[x][i]){
                                v[x][i] *= 2;
                                v[j][i] = 0;

                                j = x;
                                break;
                            }
                        }

                for(int i = 0; i < 4; i++)
                    for(int j = 3; j >= 0; j--)
                        if(v[j][i] == 0)
                            for(int x = j-1; x >= 0; x--)
                                if(v[x][i] != 0){
                                    v[j][i] = v[x][i];
                                    v[x][i] = 0;
                                    hasMoved = true;
                                    break;
                                }
                break;

            case Left:
            	for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        for(int x = j+1; x < 4; x++){
                            if(v[i][x] != 0 && v[i][j] != v[i][x])
                                break;
                            else if(v[i][j] == v[i][x]){
                                v[i][x] *= 2;
                                v[i][j] = 0;

                                j = x;
                                break;
                            }
                        }

                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        if(v[i][j] == 0)
                            for(int x = j+1; x < 4; x++)
                                if(v[i][x] != 0){
                                    v[i][j] = v[i][x];
                                    v[i][x] = 0;
                                    hasMoved = true;
                                    break;
                                }
            break;

            case Right:
            	for(int i = 0; i < 4; i++)
                    for(int j = 3; j >= 0; j--)
                        for(int x = j-1; x >= 0; x--){
                            if(v[i][x] != 0 && v[i][j] != v[i][x])
                                break;
                            else if(v[i][j] == v[i][x]){
                                v[i][x] *= 2;
                                v[i][j] = 0;

                                j = x;
                                break;
                            }
                        }

                for(int i = 0; i < 4; i++)
                    for(int j = 3; j >= 0; j--)
                        if(v[i][j] == 0)
                            for(int x = j-1; x >= 0; x--)
                                if(v[i][x] != 0){
                                    v[i][j] = v[i][x];
                                    v[i][x] = 0;
                                    hasMoved = true;
                                    break;
                                }
            break;
        }

        return hasMoved;
    }

    bool isGameLost(int v[4][4]) {
        int vCopy1[4][4], vCopy2[4][4], vCopy3[4][4], vCopy4[4][4];

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++) {
                vCopy1[i][j] = v[i][j];
                vCopy2[i][j] = v[i][j];
                vCopy3[i][j] = v[i][j];
                vCopy4[i][j] = v[i][j];
            }

        if (!updateGameMatrix(vCopy1, 4, 4, Up) && 
            !updateGameMatrix(vCopy2, 4, 4, Up) && 
            !updateGameMatrix(vCopy3, 4, 4, Up) && 
            !updateGameMatrix(vCopy4, 4, 4, Up))
            return false;
        else
            return true;
    }
}
